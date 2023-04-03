#include "docviewer.h"

DocViewer::DocViewer(IDocWidget* DocWidget):m_IDocWidget(DocWidget)
{
    //pass
}
DocViewer::~DocViewer(){
    //pass
}
void DocViewer::paintEvent(QPaintEvent *e){
    //load pdf
    QPainter* painter = new QPainter(this);
    m_IDocWidget->RenderPages(painter);
}
