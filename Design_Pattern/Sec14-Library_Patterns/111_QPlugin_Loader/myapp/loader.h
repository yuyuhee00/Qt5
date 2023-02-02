#ifndef LOADER_H
#define LOADER_H

#include <QObject>
#include <QDebug>
#include <QPluginLoader>
#include <QFileInfo>
#include <QFileInfoList>
#include <QDir>

class Loader : public QObject
{
    Q_OBJECT

public:
    explicit Loader(QObject *parent = nullptr);
    ~Loader();

    void loadPlugins(QString path);
    void execute(QString command, QStringList args);

signals:

private:
    QList<QPluginLoader*> m_plugins;
};

#endif // LOADER_H
