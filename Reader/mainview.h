#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
#include<QMenu>
#include<QMenuBar>
#include<QAction>
#include<QMdiArea>

#include"imainviewer.h"
#include"childviewer.h"
#include"multiviewer.h"


class MainView : public QMainWindow, public IMainViewer
{
    Q_OBJECT

public:
    MainView(QWidget *parent = 0);
    ~MainView();

private:
    QMenu* m_FileMenu;
    QMenu* m_EditMenu;
    QMenu* m_WindowMenu;
    QMenu* m_HelpMenu;

    QAction* m_OpenAction;
    QAction* m_SaveAction;
    QAction* m_QuitAction;

public:
    void CreateToolBar();
    void CreateActions();
    void CreateMenus();
};

#endif // MAINVIEW_H
