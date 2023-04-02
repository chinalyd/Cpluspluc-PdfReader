#ifndef VIEWMODEL_H
#define VIEWMODEL_H
#include"pdfkit.h"
#include"kit.h"
#include"viewstate.h"
#include"singlecontinuousstate.h"
#include<QWidget>
class ChildViewer;
class DocWidget;

class ViewModel
{
public:
    ViewModel(ChilsViewer* ChildViewer);
    ~ViewModel();
public:
    ChildViewer* m_ChildViewer;
    Kit* m_kit;
private:
    ViewState* m_ViewState;
    double m_DocMultiple;
public:
    int GetPageCount(){
        return m_kit->GetPageCount();
    }
    QSize GetActruallyPageSize(int nPageNum){
        return m_kit->GetActruallyPageSize(nPageNum);
    }
    QSize GetActruallyPageImage(int nPageNum){
        return m_kit->GetActruallyPageImage(nPageNum);
    }
    QImage GetPageImage(int nPageNum){
        return m_kit->GetPageImage(nPageNum);
    }
    QDomDocument* GetTOC(){
        return m_kit->GetTOC();
    }
public:
    int GetActruallyPageHighCount();//Get page height
    int GetPageHighCount();
    int GetActruallyMaxPageWidth();
    int GetMaxPageWidth();
    int GetCurPageNum(){
        return m_ViewState->GetCurPageNum();
    }
    void GotoPage(int nPageNum){
        return m_ViewState->GotoPage(nPageNum);
    }
public:
    ChildViewer* GetChildViewer(){
        return m_ChildViewer;
    }
    void SetDocMultiple(double docMultiple);
public:
    void RenderPages(QPainter* paint);

};

#endif // VIEWMODEL_H
