#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    graphScene = new QGraphicsScene();
    treeScene = new QGraphicsScene();

    graphView = ui->graphView;
    treeView = ui->treeView;

    graphView->setScene(graphScene);
    treeView->setScene(treeScene);

    loadButton = ui->loadButton;
    searchButton = ui->searchButton;

    logArea = ui->logArea;
    vertexBox = ui->vertexEdit;
    orientedGraph = ui->orientedGraph;
    currentGraphLabel = ui->currentGraphLabel;

    zoomViewGraph = new QViewZoom(graphView);
    zoomViewTree = new QViewZoom(treeView);

    zoomViewGraph->set_modifiers(Qt::NoModifier);
    zoomViewTree->set_modifiers(Qt::NoModifier);

    QObject::connect(loadButton, SIGNAL(clicked(bool)), this, SLOT(LoadClick()));
    QObject::connect(searchButton, SIGNAL(clicked(bool)), this, SLOT(SearchClick()));
    QObject::connect(orientedGraph, SIGNAL(stateChanged(int)), this, SLOT(OrientedGraphChanged()));

    WriteLog("Для увеличения изображения используйте колесо мыши, и скроллбар для прокрутки");
}

MainWindow::~MainWindow()
{
    delete ui;

    delete graphScene;
    delete treeScene;

    delete zoomViewGraph;
    delete zoomViewTree;
}

void MainWindow::LoadClick()
{
    QString fileName = QFileDialog::getOpenFileName(this,
           tr("Открыть файл"), "",
           tr("Граф (*.txt);;Все файлы (*)"));

    if (!fileName.isEmpty())
    {
        QString newPath = Utils::ToUnicodePath(fileName);
        QFile file(newPath);

        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::information(this, tr("Невозможно открыть файл!"), file.errorString());
            return;
        }

        LoadGraph(file);
    }
}

void MainWindow::SearchClick()
{
    if(graphData.isNull())
        return;

    isApplied = true;

    int start = vertexBox->currentIndex();

    Dijkstra dijkstra(graphData.data());

    GraphMatrix tree = dijkstra.FindWay(start);
    QString log = dijkstra.GetLog();

    WriteLog("---\nДерево:");
    WriteLog("Матрица\n" + Utils::MatrixToString(&tree));
    DrawGraph(treeView, treeScene, tree);
    WriteLog(log);
}

void MainWindow::OrientedGraphChanged()
{
    if(!graphData.isNull())
    {
        bool isOriented = orientedGraph->isChecked();
        GraphMatrix * matrix = graphData.data();

        matrix->SetOriented(isOriented);

        WriteLog("Перерисовываем граф");

        DrawGraph(graphView, graphScene, *graphData.data());

        /* TODO: Сохранять в кеш */
        if(isApplied)
        {
            Dijkstra dijkstra(graphData.data());
            GraphMatrix tree = dijkstra.FindWay(vertexBox->currentIndex());

            DrawGraph(treeView, treeScene, tree);
        }
    }
}

void MainWindow::LoadGraph(QFile& file)
{
    isApplied = false;

    logArea->clear();
    vertexBox->clear();
    treeScene->clear();

    currentGraphLabel->setText("Текущий граф: " + file.fileName());

    try
    {
        graphData = GraphMatrix::FromFile(file, orientedGraph->isChecked());
    }
    catch(std::exception ex)
    {
        WriteLog("Ошибка открытия файла");
        return;
    }

    for(int i = 1; i <= graphData.data()->GetSize(); i++)
    {
        vertexBox->addItem(QString::number(i));
    }

    WriteLog("---\nГраф:");
    WriteLog("Матрица\n" + Utils::MatrixToString(graphData.data()));
    DrawGraph(graphView, graphScene, *graphData.data());
}

void MainWindow::DrawGraph(QGraphicsView* view, QGraphicsScene * scene, const GraphMatrix& matrix)
{
    if(wrapper.isAvailable())
    {
        QByteArray dotRequest = wrapper.Compile(matrix);
        QPixmap graphImage = wrapper.GetImage(dotRequest);

        scene->clear();
        scene->clearSelection();
        scene->clearFocus();

        scene->setSceneRect(graphImage.rect());
        scene->addPixmap(graphImage);

        view->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    }
    else
    {
        WriteLog("GraphViz не обнаружен, невозможно отрисовать граф");
    }
}

void MainWindow::WriteLog(const QString& info)
{
    logArea->append(info + QString("\n"));
}

void MainWindow::resizeEvent(QResizeEvent*)
{
    graphView->fitInView(graphScene->sceneRect(), Qt::KeepAspectRatio);
    treeView->fitInView(treeScene->sceneRect(), Qt::KeepAspectRatio);
}

