#ifndef FILEHELPER_H
#define FILEHELPER_H

#include "pictureTypes.h"

#include <iostream>
#include <cmath>
#include <QString>
#include <QStringList>
#include <QDir>

QStringList pictureExtensions = { "jpg", "jpeg", "png" };
QStringList byteUnits = { " kB", " MB" };

struct FileCount {
    int fileCount {0};
    int subDirectoriesCount {0};
};

QString getReadableFileSizeString(const double& fileSizeInBytes)
{
    int i = -1;
    double newFileSizeInBytes = fileSizeInBytes;
    do
    {
        newFileSizeInBytes /= 1024;
        i++;
    } while (newFileSizeInBytes > 1024);

    double result = std::max(newFileSizeInBytes, 0.2);
    result = std::round(result * 100.0) / 100.0;

    return QString::number(result) + byteUnits[i];
}

void read_Folder(const QDir& origFolderDir, const bool& includeSubdirectories, FileCount& fileCount, std::vector<PictureInterface>& pictureList)
{
    const QDir folderDir = origFolderDir;
    const QFileInfoList& fileInfoList = folderDir.entryInfoList(QDir::Files | QDir::NoDot | QDir::NoDotDot | QDir::Dirs);

    foreach (const QFileInfo& fileInfo, fileInfoList)
    {
        if (fileInfo.isFile())
        {
            const QString fileExtension = fileInfo.suffix();
            if (pictureExtensions.contains(fileExtension.toLower()))
            {
                fileCount.fileCount++;
                QString fileName = fileInfo.fileName();

                PictureInterface newPictureObj;
                newPictureObj.fileName = fileName;
                newPictureObj.filePath = folderDir.absolutePath();

                QString fullFilePath = QDir(newPictureObj.filePath).filePath(newPictureObj.fileName);
                newPictureObj.fullFilePath = fullFilePath;

                pictureList.push_back(newPictureObj);
                // cout << "read_Folder() -> Check File [ " << fullFilePath.toStdString() << " ]" << endl;
            }
        }
        else if (fileInfo.isDir() && includeSubdirectories)
        {
            fileCount.subDirectoriesCount++;
            // cout << "read_Folder() -> Check Sub-Directory [ " << folderDir.absolutePath().toStdString() << " ]" << endl;

            // Check all subdirectories
            QString finalPath = fileInfo.absoluteFilePath();
            read_Folder(finalPath, includeSubdirectories, fileCount, pictureList);
        }
    }
}

FileCount check_File_Count(const QDir& folderDir, const bool& includeSubdirectories, std::vector<PictureInterface>& pictureList)
{
    FileCount fileCount;

    const auto start_time = std::chrono::high_resolution_clock::now();
    read_Folder(folderDir, includeSubdirectories, fileCount, pictureList);

    const auto end_time = std::chrono::high_resolution_clock::now();
    const auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    std::cout << "check_File_Count() -> Check File finished in [ " << elapsed_time.count() << " ] ms" << std::endl;

    return fileCount;
}

#endif // FILEHELPER_H
