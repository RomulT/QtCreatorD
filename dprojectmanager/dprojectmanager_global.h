#ifndef DPROJECTMANAGER_GLOBAL_H
#define DPROJECTMANAGER_GLOBAL_H

#include <QtGlobal>

#if defined(DPROJECTMANAGER_LIBRARY)
#  define DPROJECTMANAGERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define DPROJECTMANAGERSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // DPROJECTMANAGER_GLOBAL_H
