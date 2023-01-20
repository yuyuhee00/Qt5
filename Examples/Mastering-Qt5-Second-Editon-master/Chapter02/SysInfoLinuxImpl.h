#ifndef SYSINFOLINUXIMPL_H
#define SYSINFOLINUXIMPL_H

#include <QtGlobal>
#include <QVector>

#include "SysInfo.h"

class SysInfoLinuxImpl : public SysInfo
{
public:
    SysInfoLinuxImpl();
    ~SysInfoLinuxImpl() = default;

    SysInfoLinuxImpl(SysInfoLinuxImpl const&) = delete;
    SysInfoLinuxImpl& operator=(SysInfoLinuxImpl const&) = delete;

    SysInfoLinuxImpl(SysInfoLinuxImpl const&&) = delete;
    SysInfoLinuxImpl& operator=(SysInfoLinuxImpl const&&) = delete;

public:
    void init() override;
    double cpuLoadAverage() override;
    double memoryUsed() override;

private:
    QVector<qulonglong> cpuRawData();
    QVector<qulonglong> mCpuLoadLastValues;
};

#endif // SYSINFOLINUXIMPL_H
