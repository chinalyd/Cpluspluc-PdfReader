#ifndef SINGLECONTINUOUSSTATE_H
#define SINGLECONTINUOUSSTATE_H

#include<QScrollArea>
#include"viewstate.h"

class SingleContinuousState:public ViewState
{
public:
    SingleContinuousState(IChildViewer* childViewer);
    virtual ~SingleContinuousState();
public:
    virtual void RenderPages(QPainter* paint); //load page
    virtual int GetCurPageNum();//get current page num
    virtual void GotoPage(int nPageNum);//jump
public:
    ViewModel* m_ViewModel;
private:
    IChildViewer* m_ChildViewer;
private:
    int GetPageCount(){
        return m_ChildViewer->getPageCount();
    }
    QSize GetPageSize(int nPageNum){
        return m_ChildViewer->getPageSize(nPageNum);
    }
    int GetVScrollPos();//get vertical position
    int GetHScrollPos();//get horizontal position
    int GetPageHeightCount(int nNumPage);//get height
    bool GetVPos(int nScrollPos, int& nPageNum, int& nPageVPos);//Determine if the position is correct
};

#endif // SINGLECONTINUOUSSTATE_H
