#ifndef UTILS_H
#define UTILS_H

#include <QString>
#include <Core/graphmatrix.h>

class Utils
{
    Utils();

public:
    static QString MatrixToString(const GraphMatrix* matrix);
    static QString ToUnicodePath(const QString& path);
    static QString GetFileName(const QString& path);
};

#endif // UTILS_H
