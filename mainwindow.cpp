#include "mainwindow.h"
<<<<<<< HEAD
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
=======
#include <QDockWidget>
#include "tabwidget.h"
#include <QString>
#include <QMessageBox>
#include <QCloseEvent>
#include <QTextCodec>
#include <QTreeView>
#include <QDirModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
>>>>>>> f00fd46ea9c2e028b977141a6990a442a53c6a56
{
    QTextCodec *linuxCodec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForTr(linuxCodec);
    QTextCodec::setCodecForCStrings(linuxCodec);
    QTextCodec::setCodecForLocale(linuxCodec);
    resize(600, 600); // <-- a modificar en el futuro para permitir opciones

<<<<<<< HEAD
    pdf = new Pdf(this);
    pdf->open("/home/jjdelasheras/Descargas/bash.pdf");
    pdf->load();
    pdf->visualize();
    setCentralWidget(pdf);
=======

    menus = new Menus(this);
    dockw = new QDockWidget("Navegador", this);

    tabwidget = new TabWidget(this);
    setCentralWidget(tabwidget);
    tabwidget->setTabsClosable(true);
    tabwidget->setMovable(true);
    tab = 0;

    view.setModel(&dir);
    view.setAnimated(false);
    view.setIndentation(20);
    view.setSortingEnabled(true);

    view.show();
    dockw->setAllowedAreas(Qt::LeftDockWidgetArea);
    dockw->setWidget(&view);

    addDockWidget(Qt::LeftDockWidgetArea, dockw);
}

int MainWindow::addTab()
{
    tabwidget->addTab();
    nTab+=1;
    return nTab;
}

int MainWindow::numTab()
{
    return nTab;
}

int MainWindow::currentTab()
{
    return tab;
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    if(exitWithoutSaving()) {
        event->accept();
    }
    else                    event->ignore();
}

void MainWindow::newCurrentTab(int index)
{
    tab = index;
}

void MainWindow::setTabLabel(int index, const QString& str)
{
    tabwidget->setTabText(index, str);
}

TabWidget* MainWindow::getTabWidget() const
{
    TabWidget* ptw = tabwidget;
    return ptw;
}
bool MainWindow::exitWithoutSaving() {
    if (getTabWidget()->tabsNoSaved()) {
        QMessageBox::StandardButton ret; // es un int con un codigo
        ret = QMessageBox::warning(this, tr("Archivos modificados sin guardar"),
                     tr("Hay archivos que no han sido salvados ¿Quiere salir de todos modos?"),
                     QMessageBox::Yes | QMessageBox::No);
        if (ret == QMessageBox::Yes)
            return true;
        else if (ret == QMessageBox::No)
            return false;
    }
    return true;
}



MainWindow::~MainWindow()
{
    
>>>>>>> f00fd46ea9c2e028b977141a6990a442a53c6a56
}
