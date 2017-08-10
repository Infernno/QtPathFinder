/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *startLabel;
    QGraphicsView *treeView;
    QPushButton *searchButton;
    QLabel *currentGraphLabel;
    QPushButton *loadButton;
    QTextBrowser *logArea;
    QGraphicsView *graphView;
    QComboBox *vertexEdit;
    QCheckBox *orientedGraph;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(654, 418);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setAnimated(false);
        MainWindow->setDocumentMode(false);
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        startLabel = new QLabel(centralWidget);
        startLabel->setObjectName(QStringLiteral("startLabel"));
        startLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(startLabel, 0, 2, 1, 1);

        treeView = new QGraphicsView(centralWidget);
        treeView->setObjectName(QStringLiteral("treeView"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(treeView->sizePolicy().hasHeightForWidth());
        treeView->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(treeView, 9, 0, 1, 1);

        searchButton = new QPushButton(centralWidget);
        searchButton->setObjectName(QStringLiteral("searchButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(searchButton->sizePolicy().hasHeightForWidth());
        searchButton->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(searchButton, 3, 0, 1, 1);

        currentGraphLabel = new QLabel(centralWidget);
        currentGraphLabel->setObjectName(QStringLiteral("currentGraphLabel"));

        gridLayout->addWidget(currentGraphLabel, 0, 0, 1, 1);

        loadButton = new QPushButton(centralWidget);
        loadButton->setObjectName(QStringLiteral("loadButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(loadButton->sizePolicy().hasHeightForWidth());
        loadButton->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(loadButton, 2, 0, 1, 1);

        logArea = new QTextBrowser(centralWidget);
        logArea->setObjectName(QStringLiteral("logArea"));
        sizePolicy.setHeightForWidth(logArea->sizePolicy().hasHeightForWidth());
        logArea->setSizePolicy(sizePolicy);

        gridLayout->addWidget(logArea, 7, 1, 3, 2);

        graphView = new QGraphicsView(centralWidget);
        graphView->setObjectName(QStringLiteral("graphView"));
        sizePolicy1.setHeightForWidth(graphView->sizePolicy().hasHeightForWidth());
        graphView->setSizePolicy(sizePolicy1);
        graphView->setResizeAnchor(QGraphicsView::NoAnchor);

        gridLayout->addWidget(graphView, 8, 0, 1, 1);

        vertexEdit = new QComboBox(centralWidget);
        vertexEdit->setObjectName(QStringLiteral("vertexEdit"));
        sizePolicy3.setHeightForWidth(vertexEdit->sizePolicy().hasHeightForWidth());
        vertexEdit->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(vertexEdit, 2, 2, 1, 1);

        orientedGraph = new QCheckBox(centralWidget);
        orientedGraph->setObjectName(QStringLiteral("orientedGraph"));
        orientedGraph->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(orientedGraph, 2, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "PathFinder", Q_NULLPTR));
        action->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\275\320\276\320\262\321\213\320\271", Q_NULLPTR));
        startLabel->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\320\273\320\276", Q_NULLPTR));
        searchButton->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", Q_NULLPTR));
        currentGraphLabel->setText(QApplication::translate("MainWindow", "\320\242\320\265\320\272\321\203\321\211\320\270\320\271 \320\263\321\200\320\260\321\204: ", Q_NULLPTR));
        loadButton->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214", Q_NULLPTR));
        orientedGraph->setText(QApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204 \320\276\321\200\320\270\320\265\320\275\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
