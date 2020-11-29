#ifndef CUPUTILS_H
#define CUPUTILS_H

#include <QString>
#include <QProcess>
class CpuUtils
{
public:
    CpuUtils();
    enum MODEL{BALANCE,POWERSAVE,PERFORMANCE,UNKNOW};
    int currentModel();

private:
    const QString cmdMaxFreq="sudo -S cpupower -c all frequency-set -u 1000000GHz";//设置CPU频率为当前模式下所支持的最大值
    const QString cmdLowFreq="sudo -S cpupower -c all frequency-set -u 1.1GHz"; //设置CPU频率为固定值1.1GHz
    const QString cmdPerformance ="sudo -S cpupower -c all frequency-set -g performance";//
    const QString cmdBalance ="sudo -S cpupower -c all frequency-set -g powersave";
    const QString cmdPowersave ="sudo -S cpupower -c all frequency-set -g powersave";
    const QString cmdPolicyInfo="cpupower frequency-info -p";
    const QString FLAG_POWERSAVE="powersave";
    const QString FLAG_PERFORMANCE="performance";
    const QString LIMT_POWERSAVE="4.70 GHz";
};


#endif // CUPUTILS_H
