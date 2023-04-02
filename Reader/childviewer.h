#ifndef CHILDVIEWER_H
#define CHILDVIEWER_H
#include"readdefine.h"
#include"ichildviewer.h"
#include"naviviewer.h"
#include"docwidget.h"
#include'imainviewer.h"


class ChildViewer:public IChildViewer
{
    Q_OBJECT
public:
    ChildViewer(IMainViewer* iMainViewer);
    ~ChildViewer();
public:
    virtual QString getFileName(){
        return m_strFileName;
    }
    virtual QScrollArea* getScrollArea(){
        return m_pDocWidget->getScrollArea();
    }
    virtual int getPageCount(){
        return m_ViewModel->GetPageCount();
    }
    virtual QSize getActruallyPageSize(int nPageNum){return m_ViewModel->GetActruallyPageSize(nPageNum);}
    virtual QImage getActruallyPageImage(int nPageNum){return m_ViewModel->getActruallyPageImage(nPageNum);}
    virtual QSize getPageSize(int nPageNum){return m_ViewModel->GetPageSize(nPageNum);}
    virtual QImage getPageImage(int nPageNum){return m_ViewModel->GetPageImage(nPageNum);}
    virtual void RenderPages(QPainter *painter){m_ViewModel->RenderPages(painter);}
    virtual double getCurDocMultiple(){return m_dCurDocMultiple;}
    virtual int getActruallyPageHighCount(){return m_ViewModel->GetPageHighCount();}
    virtual int getActruallyMaxPageWidth(){return m_ViewModel->GetActruallyMaxPageWidth();}
    virtual int getMaxPageWidth(){return m_ViewModel->GetMaxPageWidth();}
    virtual QSize getCurPageNum(){return m_pDocWidget->size();}
    virtual int getCurPageNum(){return m_ViewModel->GetCurPageNum();}
    virtual QDomDocument* getTOC(){return m_ViewModel->GetTOC();}
public:
    void ZoomIn();
    void ZoomOut();
    void ZoomReset();
    void PreviousPage();
    void NextPage();
    void GotoPage(int nPageNum){
        m_ViewModel->GotoPage(nPageNum);
    }
public:
    void resizeEvent(QResizeEvent * event);
    void RefreshWindow();
private:
    ViewModel* m_ViewModel;
    DocState m_docstate;
    double m_dCurDocMultiple;
public:
    IMainViewer* m_ImainViewer;
    QString m_strFileName;
    QSplitter* m_splitterMain;
    NaviViewer* m_navigationBar;
    DocWidget* m_pDocWidget;
    QScrollBar* m_pDocWidgetScrollBar;
public slots:
    void lineEditChange();
};

#endif // CHILDVIEWER_H
