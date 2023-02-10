#ifndef SYSINFOMACIMPL_H
#define SYSINFOMACIMPL_H

#include "SysInfo.h"

#include <QtGlobal>
#include <QVector>

class SysInfoMacImpl : public SysInfo
{
public:
    SysInfoMacImpl();
    ~SysInfoMacImpl() = default;

    SysInfoMacImpl(SysInfoMacImpl const&) = delete;
    SysInfoMacImpl& operator=(SysInfoMacImpl const&) = delete;

    SysInfoMacImpl(SysInfoMacImpl const&&) = delete;
    SysInfoMacImpl& operator=(SysInfoMacImpl const&&) = delete;

public:
    void init() override;
    double cpuLoadAverage() override;
    double memoryUsed() override;

private:
    QVector<qulonglong> cpuRawData();
    QVector<qulonglong> mCpuLoadLastValues;
};

#endif // SYSINFOMACIMPL_H
