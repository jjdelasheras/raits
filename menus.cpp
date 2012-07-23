#include "menus.h"
#include "mainwindow.h"
#include "auxfunctions.h"
#include "tabwidget.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QTextDocument>
#include <QIODevice>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QDebug>

Menus::Menus(MainWindow *parent)
{
    setParent(parent);
    createFileMenu();
    createEditMenu();
/*
    createViewMenu();
    createToolsMenu();
    createProjectMenu();
    createHelpMenu();
*/
}

MainWindow *Menus::parentMW() const
{
    MainWindow* pmw = qobject_cast<MainWindow *>(parent());
    return pmw;
}

void Menus::createFileMenu()
{
    // Making actions
    fileM.newAct = new QAction(tr("Nuevo"), this);
    fileM.newAct->setShortcuts(QKeySequence::New);
    fileM.newAct->setStatusTip(tr("Crear un nuevo archivo"));
    connect(fileM.newAct, SIGNAL(triggered()), this, SLOT(newFile()));

    fileM.openAct = new QAction("Abrir", this);
    fileM.openAct->setShortcuts(QKeySequence::Open);
    fileM.openAct->setStatusTip(tr("Abrir un archivo existente"));
    connect(fileM.openAct, SIGNAL(triggered()), this, SLOT(open()));

    fileM.saveAct = new QAction("Guardar", this);
    fileM.saveAct->setShortcuts(QKeySequence::Save);
    fileM.saveAct->setStatusTip(tr("Guardar el archivo actual"));
    connect(fileM.saveAct, SIGNAL(triggered()), this, SLOT(save()));

    fileM.saveAsAct = new QAction("Guardar como", this);
    fileM.saveAsAct->setShortcuts(QKeySequence::SaveAs);
    fileM.saveAsAct->setStatusTip(tr("Guardar el archivo actual como..."));
    connect(fileM.saveAsAct, SIGNAL(triggered()), this, SLOT(saveAs()));

    fileM.quitAct = new QAction("Salir", this);
    fileM.quitAct->setShortcuts(QKeySequence::Quit);
    fileM.quitAct->setStatusTip(tr("Salir de la aplicación"));
    connect(fileM.quitAct, SIGNAL(triggered()), parent(), SLOT(close()));

    //Generamos el menu Fichero
    // El padre de esta clase será la ventana principal
    fileM.fileMenu = parentMW()->menuBar()->addMenu(tr("Fichero"));
    fileM.fileMenu->addAction(fileM.newAct);
    fileM.fileMenu->addAction(fileM.openAct);
    fileM.fileMenu->addAction(fileM.saveAct);
    fileM.fileMenu->addAction(fileM.saveAsAct);
    fileM.fileMenu->addAction(fileM.quitAct);
}

void Menus::createEditMenu() {
    //Making actions
    editM.copyAct = new QAction(tr("Copiar"), this);
    editM.copyAct->setShortcuts(QKeySequence::Copy);
    editM.copyAct->setStatusTip("Copiar el texto seleccionado");
    connect(editM.copyAct, SIGNAL(triggered()), this, SLOT(copy()));

    editM.cutAct = new QAction(tr("Cortar"), this);
    editM.cutAct->setShortcuts(QKeySequence::Cut);
    editM.cutAct->setStatusTip("Cortar el texto seleccionado");
    connect(editM.cutAct, SIGNAL(triggered()), this, SLOT(cut()));

    editM.pasteAct = new QAction(tr("Pegar"), this);
    editM.pasteAct->setShortcuts(QKeySequence::Paste);
    editM.pasteAct->setStatusTip(tr("Pegar la selección actual"));
    connect(editM.pasteAct, SIGNAL(triggered()), this, SLOT(paste()));

    editM.undoAct = new QAction(tr("Deshacer"), this);
    editM.undoAct->setShortcuts(QKeySequence::Undo);
    editM.undoAct->setStatusTip(tr("Deshacer el último cambio"));
    connect(editM.undoAct, SIGNAL(triggered()), this, SLOT(undo()));

    editM.redoAct = new QAction(tr("Rehacer"), this);
    editM.redoAct->setShortcuts(QKeySequence::Redo);
    editM.redoAct->setStatusTip(tr("Rehacer el último cambio"));
    connect(editM.undoAct, SIGNAL(triggered()), this, SLOT(redo()));

    //Generamos el menu Editar
    editM.editMenu = parentMW()->menuBar()->addMenu(tr("Editar"));
    editM.editMenu->addAction(editM.copyAct);
    editM.editMenu->addAction(editM.cutAct);
    editM.editMenu->addAction(editM.pasteAct);
    editM.editMenu->addAction(editM.undoAct);
    editM.editMenu->addAction(editM.redoAct);
}

/*
void Menus::createViewMenu() {
    //Making actions
    // ....

    //Generamos el menu Vista
    viewM.viewMenu = qobject_cast<QMainWindow *>(parent())->menuBar->addMenu(tr("Vista"));
}

void Menus::createToolsMenu() {
    //Making actions
    // ....

    //Generamos el menu herramientas
    toolsM.toolsMenu = qobject_cast<QMainWindow *>(parent())->menuBar->addMenu(tr("Herramientas"));
}

void Menus::createProjectMenu() {
    //Making actions
    // ....

    //Generamos el menu proyecto
    projectM.projectMenu = qobject_cast<QMainWindow *>(parent())->menuBar->addMenu(tr("Proyecto"));
}

void Menus::createHelpMenu() {
    //Making actions
    // ....

    //Generamos el menu ayuda
    helpM.helpMenu = qobject_cast<QMainWindow *>(parent())->menuBar->addMenu(tr("Ayuda"));
}
*/

void Menus::newFile() {
    parentMW()->addTab();
}
void Menus::open()
{
    MainWindow* prnt = parentMW();
    TabWidget* tw = prnt->getTabWidget();

    QString fileName = QFileDialog::getOpenFileName(qobject_cast<Menus *>(this));
    if(!fileName.isEmpty())  {

        QFile file(fileName);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox::warning(this, tr("Error"), tr("No se pudo leer el fichero %1:\n%2")
                                 .arg(fileName)
                                 .arg(file.errorString()));
            return;
        }
        QTextStream in(&file);
        qDebug("currentTab:%d", prnt->currentTab());

        if((tw->isEmpty(prnt->currentTab()))) {
            tw->setText(prnt->currentTab(), in.readAll());
            tw->setPath(prnt->currentTab(), fileName);

        }

        else    {

            prnt->addTab();
            tw->setText(prnt->currentTab(), in.readAll());
            tw->setPath(prnt->currentTab(), fileName);
        }

        prnt->setTabLabel(prnt->currentTab(), tail(fileName));
        tw->setChanges(prnt->currentTab(), 0);
        file.close();
    }
}

void Menus::save()
{
    MainWindow* prnt = parentMW();
    TabWidget* tw = prnt->getTabWidget();
    int index = prnt->currentTab();

    if(tw->isPathEmpty(index))
        saveAs();

    else    {
        QFile file(tw->pathText(index));
        if (!file.open(QFile::WriteOnly | QFile::Text)) {
            QMessageBox::warning(this, tr("Error"),
                                 tr("No se pudo escribir el fichero %1:\n%2.")
                                 .arg(tail(tw->pathText(index)))
                                 .arg(file.errorString()));
            return;
        }

        QTextStream out(&file);
        out << tw->text(prnt->currentTab());
        prnt->setTabLabel(index, tail(tw->pathText(index)));
        file.close();
    }
}

void Menus::saveAs()
{
    MainWindow* prnt = parentMW();
    TabWidget* tw = prnt->getTabWidget();
    QString fileName = QFileDialog::getSaveFileName(this);
    if (fileName.isEmpty())
        return;

    else    {
        QFile file(fileName);
        if (!file.open(QFile::WriteOnly | QFile::Text)) {
            QMessageBox::warning(this, tr("Error"),
                                 tr("No se pudo escribir el fichero %1:\n%2.")
                                 .arg(fileName)
                                 .arg(file.errorString()));
            return;
        }

        QTextStream out(&file);
        out << tw->text(prnt->currentTab());
        prnt->setTabLabel(prnt->currentTab(), tail(fileName));
        file.close();
    }
}

void Menus::copy()
{
    parentMW()->getTabWidget()->copy(parentMW()->currentTab());
}

void Menus::cut()
{
    parentMW()->getTabWidget()->cut(parentMW()->currentTab());
}


void Menus::paste()
{
    parentMW()->getTabWidget()->paste(parentMW()->currentTab());
}

void Menus::undo()
{
    parentMW()->getTabWidget()->undo(parentMW()->currentTab());
}

void Menus::redo()
{
    parentMW()->getTabWidget()->redo(parentMW()->currentTab());
}
