#ifndef SINGLECONTINUOUSSTATE_H
#define SINGLECONTINUOUSSTATE_H
#include"viewstate.h"

class SingleContinuousState:public ViewState
{
public:
    SingleContinuousState(IChildViewer* childViewer);
    virtual SingleContinuousState();
public:
    virtual void RenderPages(QPainter* paint);
    virtual int GetCurPageNum();
    virtual void GotoPage(int nPageNum);
public:
    ViewModel* m_ViewModel;
private:
    IChildViewer* m_ChildViewer;
private:
    int GetPageCount(){
        return m_ChildViewer->getpageCount();
    }
    QSize GetPageSize(int nPageNum){
        return m_childViewer0>getPageSize(nPageNum);
    }
    int GetVScrollPos();//get vertical position
    int GetHScrollPos();//get horizontal position
    int GetPageHeightCount(int nNumPage);//get height
    bool GetVPos(int nScrollPos, int& nPageNum, int& nPageVPos);//Determine if the position is correct
};

#endif // SINGLECONTINUOUSSTATE_H
