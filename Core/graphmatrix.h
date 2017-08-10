#ifndef GRAPHDATA_H
#define GRAPHDATA_H

#include <QFile>
#include <QSharedPointer>
#include <fstream>

/* Класс-обертка для работы с матрицей графа */
class GraphMatrix
{
    int ** matrix;
    int size;

    bool oriented;

public:
    GraphMatrix(int, bool);
    GraphMatrix(const GraphMatrix&);
    ~GraphMatrix();

    void SetOriented(bool);
    bool isOriented() const;

    int GetSize() const;
    int Get(int, int) const;

    void Set(int, int, int);
    void SetAll(int);

    static QSharedPointer<GraphMatrix> FromFile(QFile&, bool = false);
};

#endif // GRAPHDATA_H
