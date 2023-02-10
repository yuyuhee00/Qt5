#ifndef SYSINFO_H
#define SYSINFO_H


class SysInfo
{
public:
    static SysInfo& instance();
    virtual ~SysInfo() = default;

    virtual void init() = 0;
    virtual double cpuLoadAverage() = 0;
    virtual double memoryUsed() = 0;

protected:
    explicit SysInfo() = default;

public:
    SysInfo(const SysInfo&) = delete;
    SysInfo& operator=(const SysInfo&) = delete;

    SysInfo(const SysInfo&&) = delete;
    SysInfo& operator=(const SysInfo&&) = delete;
};

#endif // SYSINFO_H
