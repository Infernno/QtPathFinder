#ifndef Dijkstra_H
#define Dijkstra_H

#include <QString>
#include <QTextBrowser>
#include <Core/graphmatrix.h>

template <class T> const T& min(const T& a, const T& b) {
    return !(b < a) ? a : b;
}

class Dijkstra
{
    GraphMatrix* matrix;
    QString log;

public:
    Dijkstra(GraphMatrix*);

    GraphMatrix FindWay(int);
    QString GetLog();
};

#endif // Dijkstra_H
