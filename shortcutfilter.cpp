#include "shortcutfilter.h"

#include <xcb/xcb.h>

ShortCutFilter::ShortCutFilter()
{

}
bool ShortCutFilter::nativeEventFilter(const QByteArray &eventType, void *message, long *result){

         if (eventType == "xcb_generic_event_t") {
             xcb_generic_event_t* ev = static_cast<xcb_generic_event_t *>(message);
             qDebug()<<"============================";
             qDebug()<<ev->full_sequence;
             qDebug()<<ev->pad;
             qDebug()<<ev->pad0;
             qDebug()<<ev->sequence;
             qDebug()<<ev->response_type;
             qDebug()<<"============================";
         }
         return false;
    return false;
}
