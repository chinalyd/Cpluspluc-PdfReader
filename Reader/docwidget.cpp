#include "docwidget.h"
#include<QVBoxLayout>

DocWidget::DocWidget(IChildViewer* childviewer):m_IChildViewer(childviewer){
    setStyleSheet("backgroung-color:gray");
    m_pScrollArea = new QScrollArea();
    m_pDocViewer = new DocViewer(this);
    m_pScrollArea->setWidget(m_pDocViewer);
    QVBoxLayout* layout = new DVBoxLayout();
    setlayout(layout);
    layout->addWidget(m_pScrollArea);
    layout->setContentsMargins(1, 1, 1, 1);
    m_pScrollBar = m_pScrollArea->verticalScrollbar();
    m_pScrollArea->setAlignment(Qt::AlignCenter);
}
DocWidget::~DocWidget(){

}
void DocWidget::resizeEvent(QResizeEvent* e){
    _resize();
}
void DocWidget::RefreshWindow(){
    update();
    _resize();
}
void DocWidget::_resize(){
    if(m_IChildViewer->getMaxPageWidth() > m_pScrollArea->size().width())
        m_pDocViewer->resize(m_IChildViewer->getMaxPageWidth() + m_pScrollBar->size().width(), m_IChildViewer->getPageHighCount());
    else
        m_pDocViewer->resize(m_pScrollArea->size().width() - m_pScrollBar->size().width(), m_IChildViewer->getPageHighCount());
}
