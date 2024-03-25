#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "qheaders.h"

class FileHandler
{
public:
    QString folderPath;
    QStringList fileList;

    FileHandler();
    bool FindThemeFolder();
    bool ListThemeFolder();

};

#endif // FILEHANDLER_H
