#include "mainview.h"

MainView::MainView(QWidget *parent)
    : QMainWindow(parent)
{
    resize(QSize(800,600));
    statusBar();
    CreateActions();
    CreateMenus();
    CreateToolBar();

    m_MainMdiArea = new MultiViewer();
    setCentralWidget(m_MainMdiArea);
    connect(m_MainMdiArea, SIGNAL(subWindowActivated(QMdiSubWindow*)), this, SLOT(UpdatePageNum()));
    m_MainMdiArea->setViewMode(QMdiArea::TabbedView);

}

MainView::~MainView()
{

}
void MainView::CreateMenus(){
    m_FileMenu = menuBar()->addMenu(tr("File(F)"));
    m_FileMenu->addAction(m_OpenAction);
    m_FileMenu->addAction(m_SaveAction);
    m_FileMenu->addSeparator();
    m_FileMenu->addAction(m_QuitAction);

    m_EditMenu = new QMenu("Edit(E)");
    menuBar()->addMenu(m_EditMenu);

    m_WindowMenu = menuBar()->addMenu(tr("View(V)"));
    m_HelpMenu = menuBar()->addMenu(tr("Help(H)"));

}

void MainView::CreateToolBar(){
    //Open tool bar
    m_FileTool = new QToolBar(this);
    addToolBar(Qt::TopToolBarArea, m_FileTool);
    m_FileTool->addAction(m_OpenAction);
    m_FileTool->addAction(m_SaveAction);
    m_FileTool->addSeparator();
    m_FileTool->addAction(m_QuitAction);
    
    //zoom tool bar
    m_ZoomTool = new QToolBar(this);
    addToolBar(Qt::TopToolBarArea, m_ZoomTool);
    m_ZoomTool->addAction(m_ZoomIn);
    m_ZoomTool->addAction(m_ZoomReset);
    m_ZoomTool->addAction(m_ZoomOut);

    //Page tool bar
    m_PageTool = new QToolBar(this);
    addToolBar(Qt::TopToolBarArea, m_PageTool);
    m_PageTool->addAction(m_PreviousPage);
    m_PageTool->addAction(m_NextPage);

    m_PageNumLineEdit = new QLineEdit();
    m_PageTool->addWidget(m_PageNumLineEdit);
    m_PageNumLineEdit->setFixedWidth(30);
    m_PageNumLineEdit->setText("0");

    m_PageCountLabel->setText("  /  0");

    connect(m_PageNumLineEdit, SIGNAL(textChanged()), this, SLOT(UpdatePageNum()));
    connect(m_PageNumLineEdit, SIGNAL(returnPressed()), this, SLOT(GotoPage()));

}

void MainView::CreateActions(){
    //Open
    m_OpenAction = new QAction(QIcon(":image/open"), "Open", this);
    m_OpenAction->setShortcut(tr("Ctrl+O"));
    m_OpenAction->setStatusTip(tr("OpenFile"));
    connect(m_OpenAction, SIGNAL(triggered()), this, SLOT(OpenFile()));
    //Save
    m_SaveAction = new QAction(QIcon(":/image/save"), "Save", this);
    m_SaveAction->setShortcut(tr("Ctrl+S"));
    m_SaveAction->setStatusTip(tr("SaveFile"));
    connect(m_SaveAction, SIGNAL(triggered()), this, SLOT(SaveFile()));
    //Quit
    m_QuitAction = new QAction(QIcon(":/image/close"), "Quit", this);
    m_QuitAction->setShortcut(tr("Ctrl+Q"));
    m_QuitAction->setStatusTip(tr("Exit"));
    connect(m_QuitAction, SIGNAL(triggered()), this, SLOT(CloseFile()));
    //Zoom in
    m_ZoomIn = new QAction(QIcon(":/image/zoom_in"), "Zoom In", this);
    m_ZoomIn->setStatusTip(tr("Zoom In"));
    connect(m_ZoomIn, SIGNAL(triggered()), this, SLOT(ZoomIn()));
    //Zoom out
    m_ZoomOut = new QAction(QIcon(":/image/zoom_out"), "Zoom Out", this);
    m_ZoomOut->setStatusTip(tr("Zoom Out"));
    connect(m_ZoomOut, SIGNAL(triggered()), this, SLOT(ZoomOut()));
    //Reset
    m_ZoomReset = new QAction(QIcon(":/umage/zoom_reset"), "Reset", this);
    m_ZoomReset->setStatusTip(tr("Reset"));
    connect(m_ZoomReset, SIGNAL(triggered()), this, SLOT(ZoomReset()));
    //Previous page
    m_PreviousPage = new QAction(QIcon(":/image/previouspage"), "Prev Page", this);
    m_PreviousPage->setStatusTip(tr("Previous Page"));
    connect(m_PreviousPage, SIGNAL(triggered()), this, SLOT(PreviousPage()));
    //Next Page
    m_NextPage = new QAction(QIcon(":/image/nextpage"), "Next Page", this);
    m_NextPage->setStatusTip(tr("Next Page"));
    connect(m_NextPage, SIGNAL(triggered()), this, SLOT(NextPage()));

}

void MainView::OpenFile(){
    QString strFilter = "*.pdf";
    QString strDir = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    m_strFileName = QFileDialog::getOpenFileName(this, "Reader", strDir, strFilter);
    if(m_strFileName.isEmpty())
        return;
    NewFile();
    RefreshWindow();
}
void MainView::NewFile(){
    ChildViewer *childViewer = CreateChildViewer();
    int index = m_strFileName.lastIndexOf("/");
    QString strFileName = m_strFileName.mid((index + 1), (m_strFileName.size() - index));
    childViewer->setWindowTitle(strFileName);
    childViewer->show();
}
ChildViewer* MainView::CreateChildViewer(){
    ChildViewer *child = new ChildViewer(this);
    m_MainMdiArea->addSubWindow(child);
    return child;
}
void MainView::SaveFile(){
}
void MainView::CloseFile(){
    this->close();
}
ChildViewer* MainView::getCurChildViewer(){
    QMdiSubWindow* mdiSubWindow = m_MainMdiArea->currentSubWindow();
    if(mdiSubWindow == NULL){
        return NULL;
    }
    ChildViewer* child = static_cast<ChildViewer*>(mdiSubWindow->widget());
    Q_ASSERT(child != NULL);
    return child;
}
void MainView::ZoomIn(){
    ChildViewer* child = getCurChildViewer();
    if(child == NULL)
        return;
    child->ZoomIn();
    RefreshWindow();
}

void MainView::ZoomOut(){
    ChildViewer* child = getCurChildViewer();
    if(child == NULL)
        return;
    child->ZoomOut();
    RefreshWindow();
}
void MainView::ZoomReset(){
    ChildViewer* child = getCurChildViewer();
    if(child == NULL)
        return;
    child->ZoomReset();
    RefreshWindow();
}
void MainView::PreviousPage(){
    ChildViewer* child = getCurChildViewer();
    if(child == NULL)
        return;
    child->PreviousPage();
}
void MainView::NextPage(){
    ChildViewer* child = getCurChildViewer();
    if(child == NULL)
        return;
    child->NextPage();
}
void MainView::UpdatePageNum(){
    ChildViewer* child = getCurChildViewer();
    if(child == NULL)
        return;
    int nCurPageNum = child->getCurPageNum() + 1;
    QString str = QString::number(nCurPageNum);
    m_PageNumLineEdit->setText(str);
    int nCurPageCount = child->getPageCount();
    str = QString::number(nCurPageCount);
    str = " / " + str;
    m_PageCountLabel->setText(str);
}
void MainView::GotoPage(){
    ChildViewer* child = getCurChildViewer();
    if(child == NULL)
        return;
    QString str = m_PageNumLineEdit->text();
    int nPage = str.toInt() - 1;
    child->GotoPage(nPage);
}
void MainView::RefreshWindow(){
    ChildViewer* child = getCurChildViewer();
    if(child == NULL)
        return;
    child->RefreshWindow();
    UpdatePageNum();
}
