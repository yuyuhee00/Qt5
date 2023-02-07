#pragma once

#include <QtCore/qglobal.h>

#if defined(GALLERYCORE_LIBRARY)
#  define GALLERYCORE_EXPORT Q_DECL_EXPORT
#else
#  define GALLERYCORE_EXPORT Q_DECL_IMPORT
#endif
