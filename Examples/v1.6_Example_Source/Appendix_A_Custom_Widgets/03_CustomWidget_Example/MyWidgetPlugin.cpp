#include "MyWidget.h"
#include "MyWidgetPlugin.h"

#include <QtPlugin>

MyWidgetPlugin::MyWidgetPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void MyWidgetPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool MyWidgetPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *MyWidgetPlugin::createWidget(QWidget *parent)
{
    return new MyWidget(parent);
}

QString MyWidgetPlugin::name() const
{
    return QLatin1String("MyWidget");
}

QString MyWidgetPlugin::group() const
{
    return QLatin1String("Custom Widget");
}

QIcon MyWidgetPlugin::icon() const
{
    return QIcon(QLatin1String(":/symbol.png"));
}

QString MyWidgetPlugin::toolTip() const
{
    return QLatin1String("This is First Custom Widget");
}

QString MyWidgetPlugin::whatsThis() const
{
    return QLatin1String("This is First Custom Widget");
}

bool MyWidgetPlugin::isContainer() const
{
    return false;
}

QString MyWidgetPlugin::domXml() const
{
    return "<ui language=\"c++\">\n"
                "<widget class=\"MyWidget\" name=\"myWidget\">\n"
                    "<property name=\"geometry\">\n"
                        "<rect\n>"
                            "<x>0</x>\n"
                            "<y>0</y>\n"
                            "<width>200</width>\n"
                            "<height>100</height>\n"
                        "</rect>\n"
                    "</property>\n"
                "</widget>\n"
            "</ui>";
}

QString MyWidgetPlugin::includeFile() const
{
    return QLatin1String("MyWidget.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(MyWidgetPlugin, MyWidgetPlugin)
#endif // QT_VERSION < 0x050000
