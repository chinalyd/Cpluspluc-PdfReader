#ifndef READDEFINE_H
#define READDEFINE_H

#include<QWidget>
#include<QSplitter>
#include<QTabWidgt>
#include<QLayout>
#include<QPushButton>
#include<QScrollArea>
#include<QString>
#include<QImage>
#include<QDomDocument>
#include<QPainter>
#include<QListWidget>
#include<QTimer>
#include<QTreeWidget>
#include"float.h"

enum DocState{
    SINGLE_CONTINUOUS,
    UNSINGLE_CONTINUOUS,
    DOUBLE_CONTINUOUS,
    UNDOUBLE_CONTINUOUS
};
typedef struct _TOCInfo{
public:
    QString strDestinction;
    QString strDestinctionName;
    QString strExternalFileName;
    bool bIsOpen;
}TOCInfo;

#define DELETE_POINT(p){delete p; p = NULL;}
#define DELETE_ARRAY(p){delete[](p); (p) = NULL;}

#endif // READDEFINE_H
