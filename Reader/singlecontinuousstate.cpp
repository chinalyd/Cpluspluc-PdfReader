#include "singlecontinuousstate.h"
class DocWidget;

SingleContinuousState::SingleContinuousState(IChildViewer* childViewer):m_ChildViewer(childViewer)
{
}
SingleContinuousState::~SingleContinuousState(){
}
void SingleContinuousState::RenderPages(QPainter *paint){
    if(paint == NULL){
        return;
    }
    int nScrollHeight = 0;
    int nScrollYFlag = 0;
    nScrollHeight = m_ChildViewer->getScrollArea()->size().height();
    nScrollYFlag = GetVScrollPos();
    int nPageNum;
    int nPageVPos;
    QImage img;
    QImage imageCopy;
    int nXDrawPos = 0;
    while(nScrollHeight > 0){
        GetVPos(nScrollYFlag, nPageNum, nPageVPos);
        int nRenderHeight = GetPageSize(nPageNum).height() + 8 - nPageVPos;
        imageCopy = m_ChildViewer->getPageImage(nPageNum);
        img = imageCopy.copy(0, nPageVPos, GetPageSize(nPageNum).width(), nRenderHeight);
        QSize docWidget = m_ChildViewer->getDocWidgetSize();
        nXDrawPos = ((docWidget.width()-GetPageSize(nPageNum).width()))/2;
        if(nXDrawPos < 0)
            nXDrawPos = m_ChildViewer->getScrollArea()->verticalScrollBar()->size().width()/2;
        paint->drawImage(nXDrawPos, nScrollYFlag, img);
        nScrollHeight -= img.height();
        nScrollYFlag += img.height();
    }
}
int SingleContinuousState::GetCurPageNum(){
    int nCurPagePos = GetVScrollPos() + m_ChildViewer->getDocWidgetSize().height() / 2;
    int nPageCount = GetPageCount();
    for(int i = 0; i < nPageCount; i++){
        if(nCurPagePos < m_ChildViewer->getPageSize(i).height())
            return i;
        nCurPagePos = nCurPagePos - GetPageSize(i).height() - 8;
    }
    return 1;
}
void SingleContinuousState::GotoPage(int nPageNum){
    int nPageNumHeight = GetPageHeightCount(nPageNum);
    QScrollBar* pScrollBar = m_ChildViewer->getScrollArea()->verticalScrollBar();
    pScrollBar->setValue(nPageNumHeight);
}
int SingleContinuousState::GetVScrollPos(){
    QScrollBar* pScrollBar = m_ChildViewer->getScrollArea()->verticalScrollBar();
    return pScrollBar->value();
}
int SingleContinuousState::GetHScrollPos(){
    QScrollBar* pScrollBar = m_ChildViewer->getScrollArea()->horizontalScrollBar();
    return pScrollBar->value();
}
int SingleContinuousState::GetPageHeightCount(int nNumPage){
    //Get Page Height
    int nHeight = 0;
    for(int i = 0; i < nNumPage; i++){
        nHeight += m_ChildViewer->getPageSize(i).height() + 8;
    }
    return nHeight;
}
bool SingleContinuousState::GetVPos(int nScrollPos, int &nPageNum, int &nPageVStartPos){
    int nPageCount = GetPageCount();
    for(int i = 0; i < nPageCount; i++){
        //scroll bar less than page height
        if(nScrollPos < (GetPageSize(i).height() + 8)){
            nPageNum = i;
            nPageVStartPos = nScrollPos;
            break;
        }
        nScrollPos -= (GetPageSize(i).height() + 8);
    }
    nScrollPos += 8;
    return true;
}
