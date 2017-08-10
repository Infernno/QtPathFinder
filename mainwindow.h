#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QString>
#include <QMainWindow>
#include <QGraphicsView>
#include <QPushButton>
#include <QTextBrowser>
#include <QComboBox>
#include <QCheckBox>
#include <QLabel>
#include <QFileDialog>
#include <QMessageBox>
#include <QSharedPointer>

#include <Extensions/qviewzoom.h>
#include <GraphViz/graphvizwrapper.h>
#include <Core/graphmatrix.h>
#include <Core/dijkstra.h>
#include <Core/utils.h>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    /* Окно */
    Ui::MainWindow * ui;

    /* Для отрисовки графов */
    QGraphicsView * graphView;
    QGraphicsView * treeView;

    QGraphicsScene * graphScene;
    QGraphicsScene * treeScene;

    /* Кнопки */
    QPushButton * loadButton;
    QPushButton * searchButton;

    /* Остальные виджеты */
    QTextBrowser * logArea;
    QComboBox * vertexBox;
    QCheckBox * orientedGraph;

    QLabel * currentGraphLabel;

    /* Данные графа */
    QSharedPointer<GraphMatrix> graphData;
    GraphVizWrapper wrapper;

    QViewZoom * zoomViewGraph;
    QViewZoom * zoomViewTree;

    bool isApplied;
public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

public slots:
    void LoadClick();
    void SearchClick();
    void OrientedGraphChanged();

private:
    void LoadGraph(QFile&);
    void DrawGraph(QGraphicsView*, QGraphicsScene*, const GraphMatrix&);

    void WriteLog(const QString&);

    void resizeEvent(QResizeEvent *);
};

#endif // MAINWINDOW_H
