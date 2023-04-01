#ifndef PDFKIT_H
#define PDFKIT_H

#include<QImage>
#include<QLibrary>
#include"poppler-qt5.h"
#include"kit.h"

class PDFkit:public Kit
{
public:
    PDFkit();
    ~PDFkit();
private:
    Poppler::Page* m_pdfPage;
    Poppler::Document* m_document;
public:
    Poppler::Page* GetPage(int nPageNum);
public:
    virtual bool Init();
    virtual QImage GetActruallyPageImage(int nPageNum);
    virtual QSize GetActruallyPageSize(int nPageNum);
    virtual int GetPageCount();
    virtual QImage GetPageImage(int nPageNum);
    virtual QSize GetPageSize(int nPageNum);
    virtual QDomDocument* GetTOC();
};

#endif // PDFKIT_H
