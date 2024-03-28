#include "filehandler.h"

FileHandler::FileHandler()
{
    FindThemeFolder();
}

bool FileHandler::FindThemeFolder()
{
    QSettings ableton("HKEY_CURRENT_USER\\Software\\Ableton", QSettings::NativeFormat);
    auto cg = ableton.childGroups();
    for(auto& str:cg)
    {
        if(str[0]=='{')
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
}

bool FileHandler::ListThemeFolder()
{
    QDir dir(folderPath);
    if(!dir.exists())return false;
    fileList = dir.entryList(QDir::Files);
    return true;
}
