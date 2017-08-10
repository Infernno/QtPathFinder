#include "dijkstra.h"

Dijkstra::Dijkstra(GraphMatrix * matrix)
{
    this->matrix = matrix;
}

GraphMatrix Dijkstra::FindWay(int start)
{
    const int inf = 1000000000;

    int s = start;
    int n = matrix->GetSize();

    int * d = new int[n];
    bool * used = new bool[n];

    GraphMatrix g(*matrix);
    GraphMatrix g1(n, matrix->isOriented());

    g1.SetAll(-1);

    for (int i = 0; i < n; i++)
        d[i] = inf;

    d[s] = 0;

    for (int k = 0; k < n; k++)
    {
        g1.SetAll(-1);

        for (int i = 0; i < n; i++)
            used[i] = false;

        for (int i = 0; i < n; i++)
        {
            int v = -1;

            for (int j = 0; j < n; j++)
                if (!used[j])
                    if (v == -1)
                        v = j;

            used[v] = true;

            for (int j = 0; j < n; j++)
            {
                if (g.Get(v, j) != -1 && i != j && d[v] + g.Get(v, j) <= d[j])
                {
                    g1.Set(v, j, g.Get(v, j));
                    d[j] = min(d[v] + g.Get(v, j), d[j]);
                }

                if(g.Get(j, v) != -1)
                {
                    if(d[v] + g.Get(j, v) <= d[j])
                        g1.Set(j, v, g.Get(j, v));

                    d[j] = min(d[v] + g.Get(j, v), d[j]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (d[i] == inf)
        {
            log.append("-1\n");
        }
        else if (i != s)
        {
            log.append(QString("Минимальная доставка до пункта %1 обойдется в %2\n")
                       .arg(QString::number(i + 1), QString::number(d[i])));
        }
    }

    delete[] used;
    delete[] d;

    return g1;
}

QString Dijkstra::GetLog()
{
    return log;
}
