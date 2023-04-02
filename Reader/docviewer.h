#ifndef DOCVIEWER_H
#define DOCVIEWER_H

#include<QWidget>
#include<QScrollArea>
#include<QPainter>
#include"ichildviewer.h"
#include"viewmodel.h"
#include'idocwidget.h"


class DocViewer:public QWidget
{
public:
    DocViewer(IDocWidget* DocWidget);
    ~DocViewer();
public:
    QScrollArea* m_pscrollarea;
    QScrollBar* m_pScrollBar;
    IDocWidget* m_IDocWidget;
public:
    void paintEvent(QPaintEvent *e);//load pdf
    QScrollArea* getScroll(){//load scroll bar
        return m_pscrollarea;
    }
};

#endif // DOCVIEWER_H
