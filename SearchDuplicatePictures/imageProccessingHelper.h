#ifndef IMAGEPROCCESSINGHELPER_H
#define IMAGEPROCCESSINGHELPER_H

#include "fileHelper.h"
#include "pictureTypes.h"

#include <vector>
#include <opencv4/opencv2/opencv.hpp>
#include <QString>
#include <QFileInfo>
#include <QPicture>
#include <QPainter>
#include <QImage>
#include <QElapsedTimer>

// Create SIFT feature detector and descriptor extractor
cv::Ptr<cv::SIFT> detector = cv::SIFT::create();

QPicture convert_CvImage_To_QPicture(const cv::Mat& imgToConvert)
{
    QImage imgIn = QImage((uchar*) imgToConvert.data, imgToConvert.cols, imgToConvert.rows, imgToConvert.step, QImage::Format_RGB888);
    QPicture convertedPicture;
    QPainter painter(&convertedPicture);
    painter.drawImage(QPoint(0, 0), imgIn);
    painter.end();

    return convertedPicture;
}

PictureSFITData generate_SIFT_Data_For_Picture(PictureInterface& pictureItem)
{
    QElapsedTimer timer;
    timer.start(); // Start the timer

    PictureSFITData imageData = {};
    // std::cout << "Gen data for [ " << pictureItem.fullFilePath.toStdString() << " ]" << std::endl;

    cv::Mat imgData = cv::imread(pictureItem.fullFilePath.toStdString());
    imageData.image_Height = imgData.rows;
    imageData.image_Width = imgData.cols;

    const double fileSizeByte = QFileInfo(pictureItem.fullFilePath).size();
    imageData.image_Size = getReadableFileSizeString(fileSizeByte);

    // TODO: Resize Image
    imageData.imageObj = imgData;
    detector->detectAndCompute(imgData, cv::noArray(), imageData.keypoints, imageData.descriptors);

    qint64 elapsedTime = timer.elapsed();
    std::cout << "generate_SIFT_Data_For_Picture(): File [ " << pictureItem.fileName.toStdString() << " ] with [ " << imageData.image_Size.toStdString() << " ] Processing time in ms: " << elapsedTime << std::endl;

    return imageData;
}

float computeIoU(const PictureSFITData& picture_1, const PictureSFITData& picture_2)
{
    cv::Ptr<cv::DescriptorMatcher> matcher = cv::DescriptorMatcher::create(cv::DescriptorMatcher::FLANNBASED);

    std::vector<cv::DMatch> matches;
    matcher->match(picture_1.descriptors, picture_2.descriptors, matches);

    std::vector<cv::Point2f> pts1, pts2;
    for (const auto& match : matches) {
        pts1.push_back(picture_1.keypoints[match.queryIdx].pt);
        pts2.push_back(picture_2.keypoints[match.trainIdx].pt);
    }

    cv::Mat mask;
    cv::Mat H = cv::findHomography(pts1, pts2, cv::RANSAC, 5.0, mask);

    cv::Mat img1_warped;
    cv::warpPerspective(picture_1.imageObj, img1_warped, H, picture_2.imageObj.size());

    cv::Mat img_diff;
    cv::absdiff(img1_warped, picture_2.imageObj, img_diff);
    cv::cvtColor(img_diff, img_diff, cv::COLOR_BGR2GRAY);

    int intersection = cv::countNonZero(img_diff == 0);
    int union_ = img_diff.rows * img_diff.cols;

    float iou = static_cast<float>(intersection) / static_cast<float>(union_);
    return iou;
}

#endif // IMAGEPROCCESSINGHELPER_H
