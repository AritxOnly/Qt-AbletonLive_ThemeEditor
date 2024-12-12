#include "filehandler.h"
#include <iostream>

FileHandler::FileHandler()
{
    FindThemeFolder();
}

bool FileHandler::FindThemeFolder()
{
#ifdef Q_OS_WIN
    QSettings ableton("HKEY_CURRENT_USER\\Software\\Ableton", QSettings::NativeFormat);
    auto cg = ableton.childGroups();
    for(auto& str:cg)
    {
        if(!str.isEmpty() && str[0]=='{')
        {
            QSettings st("HKEY_CURRENT_USER\\Software\\Ableton\\"+str, QSettings::NativeFormat);
            QString path = st.value("InstallPath").toString();

            if(path.endsWith("Live 12 Suite"))
            {
                folderPath = path + "\\Resources\\Themes\\";
                return true;
            }
        }
    }
    return false;
#endif
#ifdef Q_OS_MACOS
    // for macOS
    QString liveDir = "/Applications/Ableton\ Live\ 12\ Suite.app";
    folderPath = liveDir + "/Contents/App-Resources/Themes/";

    return true;
#endif
}

bool FileHandler::ListThemeFolder()
{
    QDir dir(folderPath);
    if(!dir.exists())
    {
        std::cout << "Not exist\n";
        return false;
    }
    fileList = dir.entryList(QDir::Files);
    return true;
}
