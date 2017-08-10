#include "graphvizwrapper.h"

GraphVizWrapper::GraphVizWrapper()
{

}

QString GraphVizWrapper::GetPath()
{
    return QString("%1%2graphviz%2bin%2dot.exe")
            .arg(QCoreApplication::applicationDirPath(), QDir::separator());
}

QByteArray GraphVizWrapper::Compile(const GraphMatrix &graph)
{
    QString keyword = graph.isOriented() ? "digraph" : "graph";
    QString connector = graph.isOriented() ? "->" : "--";

    QString output;
    QByteArray bytes;

    QTextStream stream(&bytes, QIODevice::ReadWrite);

    output.append(keyword + " graph1 {\n");
    output.append("\trankdir=\"LR\"\n");

    for(int i = 1; i <= graph.GetSize(); i++)
        output.append(QString("\tv%1\n").arg(QString::number(i)));

    for(int i = 0; i < graph.GetSize(); i++)
    {
        for(int j = 0; j < graph.GetSize(); j++)
        {
            int weight = graph.Get(i, j);

            if(!graph.isOriented())
            {
                if((j >= i) == false)
                    continue;
            }

            if(weight != -1)
            {
                output.append(QString("\tv%1 %3 v%2\n").arg(QString::number(i + 1), QString::number(j + 1), connector));
                output.append("\t[\n");
                output.append(QString("\t\tlabel=%1\n").arg(QString::number(weight)));
                output.append("\t]\n");
            }
        }
    }

    output.append("}\n");

    stream << output;
    stream.flush();

    return bytes;
}

bool GraphVizWrapper::isAvailable()
{
    return QFile(GetPath()).exists();
}

QPixmap GraphVizWrapper::GetImage(const QByteArray &request)
{
    QProcess proc;

    QByteArray imageBytes;
    QPixmap pixmap;

    proc.setProcessChannelMode(QProcess::MergedChannels);
    proc.start(GetPath(), QStringList() << "-Tpng");
    proc.waitForStarted();
    proc.write(request);
    proc.waitForBytesWritten();
    proc.closeWriteChannel();

    while (proc.waitForReadyRead(-1))
        imageBytes.append(proc.readAll());

    pixmap.loadFromData(imageBytes);

    return pixmap;
}
