#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pdf.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Pdf* pdf;
public:
    explicit MainWindow(QWidget *parent = 0);
    
signals:
    
public slots:
    
};

#endif // MAINWINDOW_H
