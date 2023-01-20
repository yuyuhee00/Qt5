#ifndef SYSINFOWINDOWSIMPL_H
#define SYSINFOWINDOWSIMPL_H

#include <QtGlobal>
#include <QVector>

#include "SysInfo.h"

typedef struct _FILETIME FILETIME;

class SysInfoWindowsImpl : public SysInfo
{
public:
    SysInfoWindowsImpl();
    ~SysInfoWindowsImpl() = default;

    SysInfoWindowsImpl(SysInfoWindowsImpl const&) = delete;
    SysInfoWindowsImpl& operator=(SysInfoWindowsImpl const&) = delete;

    SysInfoWindowsImpl(SysInfoWindowsImpl const&&) = delete;
    SysInfoWindowsImpl& operator=(SysInfoWindowsImpl const&&) = delete;

public:

    void init() override;
    double cpuLoadAverage() override;
    double memoryUsed() override;

private:
    QVector<qulonglong> cpuRawData();
    qulonglong convertFileTime(const FILETIME& filetime) const;
    QVector<qulonglong> mCpuLoadLastValues;
};

#endif // SYSINFOWINDOWSIMPL_H
