#include "childviewer.h"

ChildViewer::ChildViewer(IMainViewer* iMainViewer):m_IMainViewer(iMainViewer),m_docstate(SINGLE_CONTINUOUS),m_dCurDocMultiPle(1){
    //shut down all the window
    setAttribute(Qt::WA_DeleteOnClose);

}

