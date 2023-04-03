#include "childviewer.h"

ChildViewer::ChildViewer(IMainViewer* iMainViewer):m_IMainViewer(iMainViewer),m_docstate(SINGLE_CONTINUOUS),m_dCurDocMultiple(1){
    //shut down all the window
    setAttribute(Qt::WA_DeleteOnClose);
    m_strFileName = m_IMainViewer->getFileName();
    m_splitterMain = new QSplitter(Qt::Horizontal, this);
    m_splitterMain->setHandleWidth(1);
    m_ViewModel = new ViewModel(this);
    m_navigationBar = new NaviViewer(this);
    m_pDocWidget = new DocWidget(this);
    m_splitterMain->addWidget(m_navigationBar);
    m_splitterMain->addWidget(m_pDocWidget);
    m_splitterMain->setStretchFactor(1, 1);
    m_splitterMain->setAutoFillBackground(true);
    m_splitterMain->show();
    m_pDocWidgetScrollBar = m_pDocWidget->getScrollArea()->verticalScrollBar();
    connect(m_pDocWidgetScrollBar, SIGNAL(valueChanged(int)), this, SLOT(lineEditChange()));
}
void ChildViewer::RefreshWindow(){
    m_pDocWidget->RefreshWindow();
}
void ChildViewer::ZoomIn(){
    m_dCurDocMultiple += 0.25;
    m_dCurDocMultiple = m_dCurDocMultiple > 2 ? 2 : m_dCurDocMultiple;
    m_ViewModel->SetDocMultiple(m_dCurDocMultiple);
}
void ChildViewer::ZoomOut(){
    m_dCurDocMultiple -= 0.25;
    m_dCurDocMultiple = m_dCurDocMultiple < 0.25 ? 0.25 : m_dCurDocMultiple;
    m_ViewModel->SetDocMultiple(m_dCurDocMultiple);
}
void ChildViewer::ZoomReset(){
    m_dCurDocMultiple = 1;
    m_ViewModel->SetDocMultiple(1);
}
void ChildViewer::PreviousPage(){
    int nPageNum = getCurPageNum();
    int nCurPageNum = (nPageNum == 0) ? 0 : (nPageNum - 1);
    m_ViewModel->GotoPage(nCurPageNum);
}
void ChildViewer::NextPage(){
    int nPageNum = getCurPageNum();
    int nPageCount = getPageCount();
    int nCurPageNum = (nPageNum == nPageCount) ? nPageCount : (nPageNum + 1);
    m_ViewModel->GotoPage(nCurPageNum);
}
void ChildViewer::lineEditChange(){
    //page frame update
    int nPageNum = getCurPageNum() + 1;
    QLineEdit* lineEdit = m_IMainViewer->getPageNumLineEdit();
    QString strPageNum = QString::number(nPageNum);
    lineEdit->setText(strPageNum);
}

