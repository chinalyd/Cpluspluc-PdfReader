#ifndef KIT_H
#define KIT_H
#include"readdefine.h"

class Kit
{
public:
    Kit();
    virtual ~Kit(){}
public:
    virtual bool Init() = 0;
public:
    virtual QImage GetActruallyPageImage(int nPageNum) = 0;
    virtual QSize GetActruallyPageSize(int nPageNum) = 0;
    virtual int GetPageCount() = 0;
    virtual QImage GetPageImage(int nPageNum) = 0;
    virtual QSize GetPageSize(int nPageNum) = 0;
    virtual QDomDocument* GetTOC() = 0;
public:
    void SetFileName(QString strFileName){
        m_strFileName = strFileName;
    }
    void SetDocMultiple(double multiple){
        m_multiple = multiple;
    }
public:
    QString m_strFileName;
    double m_multiple; //magnification times
};

#endif // KIT_H
