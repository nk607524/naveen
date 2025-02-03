#include "AppMainWindow.h"
#include <QFile>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication l_objApplication(argc, argv);

    //Apply global Stylesheet
    QFile l_objFile(":/AppMainWindow/Resources/StyleSheet.qss");
    if (l_objFile.open(QFile::ReadOnly))
    {
        QString l_strStyleSheet = QLatin1String(l_objFile.readAll());
        l_objApplication.setStyleSheet(l_strStyleSheet);
        l_objFile.close();
    }
    
    QSharedPointer<AppMainWindow> l_pAppMainWindow = AppMainWindow::getInstance();
    l_pAppMainWindow->showMaximized();

    return l_objApplication.exec();
}
