#include "mainview.h"

MainView::MainView(QWidget *parent)
    : QMainWindow(parent)
{
    resize(QSize(800,600));
    statusBar();
    CreateBar();
    CreateMenus();
    CreateToolBar();

}

MainView::~MainView()
{

}
void MainViewer::CreateMenus(){
    m_FileMenu = menuBar()->addMenu(tr('File(F)'));
    m_FileMenu->addAction(m_OpenAction);
    m_FileMenu->addAction(m_SaveAction);
    m_FileMenu->addSeparator();
    m_FileMenu->addAction(m_QuitAction);

    m_EditMenu = new QMenu('Edit(E)');
    menuBar()->addMenu(m_EditMenu);

    m_WindowsMenu = menuBar()->addMenu(tr('View(V)'));
    m_HelpMenu = menuBar()->addMenu(tr('Help(H)'));

}
