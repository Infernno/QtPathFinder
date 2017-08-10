#ifndef GVBRIDGE_H
#define GVBRIDGE_H

#include <QString>
#include <QCoreApplication>
#include <QTextStream>
#include <QProcess>
#include <QPixmap>
#include <QFile>
#include <QDir>

#include <Core/graphmatrix.h>
#include <Core/utils.h>

/* Класс-обертка для работы с GraphViz */
class GraphVizWrapper
{
public:
    GraphVizWrapper();

    QByteArray Compile(const GraphMatrix&);
    QPixmap GetImage(const QByteArray&);

    bool isAvailable();

private:
     static QString GetPath();
};

#endif // GVBRIDGE_H
