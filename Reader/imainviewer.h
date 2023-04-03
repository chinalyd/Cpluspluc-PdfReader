#ifndef IMAINVIEWER_H
#define IMAINVIEWER_H

#include<QMainWindow>
#include<QLineEdit>
class IMainViewer
{
public:
    IMainViewer();
    virtual ~IMainViewer(){}
 
public:
    virtual QString getFileName() = 0;
    virtual QLineEdit* getPageNumLineEdit() = 0;
};

#endif // IMAINVIEWER_H
