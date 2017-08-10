#include "utils.h"

Utils::Utils()
{

}

QString Utils::MatrixToString(const GraphMatrix *matrix)
{
    QString out;

    for(int i = 0; i < matrix->GetSize(); i++)
    {
        for(int j = 0; j < matrix->GetSize(); j++)
        {
            out.append(QString("%1 ").arg(matrix->Get(i, j)));
        }

        out.append("\n");
    }

    return out;
}

QString Utils::ToUnicodePath(const QString &path)
{
    QByteArray bytes = path.toLocal8Bit();

    return QString::fromLocal8Bit(bytes);
}

QString Utils::GetFileName(const QString &path)
{
    int index = path.lastIndexOf("\\");

    return path.right(index);
}
