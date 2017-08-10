#include "graphmatrix.h"
#include <QTextStream>

GraphMatrix::GraphMatrix(int count, bool isOriented)
{
    size = count;
    oriented = isOriented;

    matrix = new int*[size];

    for(int i = 0; i < size; i++)
        matrix[i] = new int[size];
}

GraphMatrix::GraphMatrix(const GraphMatrix & copy) : GraphMatrix(copy.GetSize(), copy.isOriented())
{
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            matrix[i][j] = copy.Get(i, j);
}

GraphMatrix::~GraphMatrix()
{
    for(int i = 0; i < size; i++)
        delete[] matrix[i];

    delete[] matrix;
}

bool GraphMatrix::isOriented() const
{
    return oriented;
}

void GraphMatrix::SetOriented(bool value)
{
    oriented = value;
}

int GraphMatrix::GetSize() const
{
    return size;
}

int GraphMatrix::Get(int i, int j) const
{
    return matrix[i][j];
}

void GraphMatrix::Set(int i, int j, int value)
{
    matrix[i][j] = value;
}

void GraphMatrix::SetAll(int value)
{
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            matrix[i][j] = value;
}

QSharedPointer<GraphMatrix> GraphMatrix::FromFile(QFile& file, bool oriented)
{
    QTextStream input(&file);

    int n;
    input >> n;

    GraphMatrix * data = new GraphMatrix(n, oriented);

    for(int i = 0; i < data->GetSize(); i++)
    {
        for(int j = 0; j < data->GetSize(); j++)
        {
            input >> n;
            data->Set(i, j, n);
        }
    }

    return QSharedPointer<GraphMatrix>(data);
}

