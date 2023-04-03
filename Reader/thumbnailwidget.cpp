#include "thumbnailwidget.h"

ThumbnailWidget::ThumbnailWidget(IChildViewer* childViewer):m_IChildViewer(childViewer), m_nCurThumbDrawPageNum(0),m_nPageCount(0){
    m_nTimerIdle = startTimer(0);
    m_vBoxlayout = new QVBoxLayout(this);
    m_listView = new QListView();
    m_listView->setViewMode(QListView::IconMode);
    m_listView->setSpacing(10);
    m_listView->setIconSize(QSize(150, 300));
    m_listView->setModelColumn(1);
    m_listView->setResizeMode(QListView::Adjust);
    m_ItemModel = new QStandardItemModel();
    m_listView->setModel(m_ItemModel);
    m_vBoxlayout->addWidget(m_listView);
    m_vBoxlayout->setContentsMargins(1, 1, 1, 1);
    m_nPageCount = m_IChildViewer->getPageCount();
}
ThumbnailWidget::~ThumbnailWidget(){

}
void ThumbnailWidget::timerEvent(QTimerEvent *){
    if(m_nCurThumbDrawPageNum >= m_nPageCount)
        return;
    QImage img; //get page image
    img = m_IChildViewer->getActruallyPageImage(m_nCurThumbDrawPageNum);
    QPixmap pixmap; //create the canvas
    pixmap = QPixmap::fromImage(img);//page num convert to character
    QString strPageNum = QString::number(m_nCurThumbDrawPageNum + 1);
    QStandardItem* item = new QStandardItem(QIcon(pixmap), strPageNum);
    m_ItemModel->appendRow(item);
    m_nCurThumbDrawPageNum++;
}
