#ifndef PICTURETYPES_H
#define PICTURETYPES_H

#include <QString>
#include <opencv4/opencv2/opencv.hpp>

struct PictureInterface {
    QString fileName;
    QString filePath;
    QString fullFilePath;
};

struct PictureSFITData {
    QString fullFilePath;
    int image_Height;
    int image_Width;
    QString image_Size;
    std::vector<cv::KeyPoint> keypoints;
    cv::Mat descriptors;
    cv::Mat imageObj;
};

#endif // PICTURETYPES_H
