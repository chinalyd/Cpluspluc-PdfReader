#ifndef THUMBNAILWIDGET_H
#define THUMBNAILWIDGET_H

#include"readdefine.h"
#include"ichildviewer.h"
#include<QStandardItem>


class ThumbnailWidget:public QWidget
{
    Q_OBJECT
public:
    ThumbnailWidget(IChildViewer* childviewer);
    ~ThumbnailWidget();
private:
    IChildViewer* m_IChildViewer;
    QVBoxLayout* m_vBoxlayout;
    int m_nTimerIdle;
    QListView* m_listView;
    QStandardItemModel* m_ItemModel;
    int m_nCurThumbDrawPageNum;
    int m_nPageCount;
private:
    void timerEvent(QTimerEvent*);
};

#endif // THUMBNAILWIDGET_H
