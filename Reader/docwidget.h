#ifndef DOCWIDGET_H
#define DOCWIDGET_H
#include"idocwidget.h"
#include"viewmodel.h"
#include"docviewer.h"

class IChildViewer;
class DocWidget:public IDocWidget{
    Q_OBJECT
public:
    DocWidget(IChildViewer* childviewer);
    virtual ~DocWidget();
public:
    virtual int getPageCount(){
        return m_IChildViewer->getPageCount();
    }
    virtual QSize getActruallyPageSize(int nPageNum){
        return m_IChildViewer->getActruallyPageSize(nPageNum);
    }
    virtual QImage getactruallyPageImage(int nPageNum){
        return m_IChildVIewer->getActruallyPageImage(nPageNum);
    }
    virtual void RenderPages(QPainter *painter){
        m_IChilderViewer->RenderPages(painter);
    }
    virtual QScrollArea* getScrollArea(){
        return m_pScrollArea;
    }
public:
    QScrollArea* m_pScrollArea;
    QScrollBar* m_pScrollBar;
    IChildViewer* m_IChildViewer;
    DocViewer* m_pDocViewer;
public:
    QScrollArea* getScroll(){
        return m_pScrollArea;
    }
    void RefreshWindoW();
public:
    void resizeEvent(QResizeEvent* e);
private:
    void _resize();
};


#endif // DOCWIDGET_H
