#ifndef COREITEM_H
#define COREITEM_H

#include <QWidget>
#include <QGroupBox>
#include <QLCDNumber>
#include <QProgressBar>
#include <QSlider>
#include <QSpinBox>

class CoreItem : public QWidget
{
    Q_OBJECT
public:
    explicit CoreItem(QWidget *parent = nullptr):QWidget(parent)
        {
        this->setMinimumSize(112,394);
        croeItemBox = new QGroupBox(this);
        croeItemBox->setObjectName(QString::fromUtf8("croeItemBox"));
        croeItemBox->setGeometry(QRect(10, 0, 109, 391));
        croeItemBox->setMinimumSize(QSize(109, 0));
        croeItemBox->setAlignment(Qt::AlignCenter);
        croeItemBox->setFlat(false);
        croeItemBox->setTitle("All Core");
        frequencyNumber = new QLCDNumber(croeItemBox);
        frequencyNumber->setObjectName(QString::fromUtf8("frequencyNumber"));
        frequencyNumber->setGeometry(QRect(10, 160, 91, 21));
        frequencyNumber->setLayoutDirection(Qt::LeftToRight);
        frequencyNumber->setSmallDecimalPoint(false);
        frequencyNumber->setSegmentStyle(QLCDNumber::Flat);
        frequencyNumber->setProperty("intValue", QVariant(10000));
        frequencyBar = new QProgressBar(croeItemBox);
        frequencyBar->setObjectName(QString::fromUtf8("frequencyBar"));
        frequencyBar->setGeometry(QRect(42, 30, 31, 121));
        frequencyBar->setValue(24);
        frequencyBar->setAlignment(Qt::AlignCenter);
        frequencyBar->setTextVisible(false);
        frequencyBar->setOrientation(Qt::Vertical);
        frequencyBar->setInvertedAppearance(true);
        frequencySlider = new QSlider(croeItemBox);
        frequencySlider->setObjectName(QString::fromUtf8("frequencySlider"));
        frequencySlider->setGeometry(QRect(47, 230, 20, 151));
        frequencySlider->setOrientation(Qt::Vertical);
        spinBox = new QSpinBox(croeItemBox);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(10, 190, 94, 30));
        spinBox->setStyleSheet(QString::fromUtf8("QSpinBox\n"
"{\n"
"	border:1px solid #242424;\n"
"}\n"
" \n"
"QSpinBox::up-button,QSpinBox::down-button\n"
"{\n"
"	width:0px;\n"
"}"));
    //bind event
        connect(frequencySlider,SIGNAL(valueChanged(int)),spinBox,SLOT(setValue(int)));
    }


private:
    QWidget *coreItem;
    QGroupBox *croeItemBox;
    QLCDNumber *frequencyNumber;
    QProgressBar *frequencyBar;
    QSlider *frequencySlider;
    QSpinBox *spinBox;

signals:

};

#endif // COREITEM_H
