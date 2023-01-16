#include <QCoreApplication>

/*
 What
 Use a lib without creating a dependacy tree

 Description
 We dont want to enforce linking to QtNetwork

 Why
 Because we want to load this lib dynamically

 Example
 Loading a lib
    https://doc.qt.io/qt-5/qlibrary.html#resolve

    WHAT A PAIN
 */


#include <QDebug>
#include <QLibrary>

bool loadlib(QLibrary *lib, QString path)
{
    lib->setFileName(path);
    lib->setLoadHints(QLibrary::ResolveAllSymbolsHint);

    if(!lib->load())
    {
        qWarning() << "Failed to load the lib!";
        qWarning() << lib->errorString();
        return false;
    }

    return lib->isLoaded();

}

void callFunction(QLibrary *lib)
{
    double value = -1;
    typedef int (*AvgFunction)(int, int);
    AvgFunction avg = (AvgFunction) lib->resolve("avg");

    if(avg) value = avg(5,8);
    qInfo() << value;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString path = "/Users/yuyuhee/Language/C++/Qt5/build-Design_Pattern-Desktop_x86_darwin_generic_mach_o_64bit-Debug/Sec14-Library_Patterns/110_Loading_Lib_Dynamically/bla/libbla.1.0.0.dylib";
    QLibrary lib;

    //load
    if(loadlib(&lib, path))
    {
        //use
        callFunction(&lib);

        //unload the lib when we are done
        lib.unload(); //will return false if being used by something else!
    }

    return a.exec();
}
