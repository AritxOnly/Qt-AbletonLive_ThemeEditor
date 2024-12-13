#include "filehandler.h"
#include <iostream>

FileHandler::FileHandler()
{
    bool succ = FindThemeFolder();

    if (!succ) {
        auto path =
#ifdef Q_OS_MACOS
            QFileDialog::getOpenFileName(nullptr,
                                         "Select your Live installation (.app) path",
                                         "/Applications",
                                         "Applications (*.app)");
#else
        QFileDialog::getExistingDirectory(nullptr,
                                          "Select your Live installation path",
                                          "",
                                          QFileDialog::ShowDirsOnly);
#endif

        auto s = QDir::separator();

#ifdef Q_OS_MACOS
        if (path.isEmpty() && !path.endsWith(".app")) {
            QMessageBox::warning(nullptr, "Invalid Selection", "Please select a valid .app directory.");
            return;
        }
#endif

        auto pathList = {
#ifdef Q_OS_WIN
            path + s + "Resources" + s + "Themes",
            path + s + ".." + s + "Resources" + s + "Themes",
#endif
            path + s + ".." + s + "Themes",
#ifdef Q_OS_MACOS
            path + s + "Contents" + s + "App-Resources" + s + "Themes",
            path + s + "App-Resources" + s + "Themes",
            path + s + ".." + s + "App-Resources" + s + "Themes",
#endif
            path + s + "Themes",
            path,
        };

        for (const auto& each : pathList) {
            QDir dir(each);
            if (dir.exists()) {
                folderPath = each;
                break;
            }
        }
    }
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
