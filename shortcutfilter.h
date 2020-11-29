#ifndef SHORTCUTFILTER_H
#define SHORTCUTFILTER_H

#include <QAbstractNativeEventFilter>
#include <QtDebug>
class ShortCutFilter:public QAbstractNativeEventFilter
{
public:
    ShortCutFilter();
    bool nativeEventFilter(const QByteArray &eventType, void *message, long *result) override;
};

#endif // SHORTCUTFILTER_H
