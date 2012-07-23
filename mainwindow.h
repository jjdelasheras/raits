#ifndef MAINWINDOW_H
#define MAINWINDOW_H

<<<<<<< HEAD
#include <QMainWindow>
#include "pdf.h"
=======
#include <QtGui/QMainWindow>
#include <QDockWidget>
#include <QTreeView>
#include <QDirModel>
#include "menus.h"

class TabWidget;
>>>>>>> f00fd46ea9c2e028b977141a6990a442a53c6a56

class MainWindow : public QMainWindow
{
    Q_OBJECT
<<<<<<< HEAD
private:
    Pdf* pdf;

public:
    explicit MainWindow(QWidget *parent = 0);
    
signals:
    
public slots:
    
=======
protected:
    void closeEvent(QCloseEvent *);

private:
    QTreeView view;
    QDirModel dir;
    QDockWidget* dockw;
    int nTab;
    Menus* menus;
    TabWidget* tabwidget;
    int tab;

public slots:
    void newCurrentTab(int index);

public:
    MainWindow(QWidget *parent = 0);
    int currentTab();
    int addTab();
    int numTab();
    void setTabLabel(int index, const QString& str);
    TabWidget* getTabWidget() const;
    const QString pathText(int index);
    const QString getText(int index);
    bool exitWithoutSaving();


    ~MainWindow();
>>>>>>> f00fd46ea9c2e028b977141a6990a442a53c6a56
};

#endif // MAINWINDOW_H
