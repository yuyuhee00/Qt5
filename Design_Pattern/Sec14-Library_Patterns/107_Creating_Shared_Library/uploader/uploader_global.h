#ifndef UPLOADER_GLOBAL_H
#define UPLOADER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(UPLOADER_LIBRARY)
#  define UPLOADER_EXPORT Q_DECL_EXPORT
#else
#  define UPLOADER_EXPORT Q_DECL_IMPORT
#endif

#endif // UPLOADER_GLOBAL_H
