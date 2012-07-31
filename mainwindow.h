#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pdfviewer.h"
#include "imageviewer.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    PdfViewer* pdf;
public:
    explicit MainWindow(QWidget *parent = 0);
    
signals:
    
public slots:
    
};

#endif // MAINWINDOW_H
