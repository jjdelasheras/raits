#include "mainwindow.h"
#include <QTextCodec>
#include <QScrollArea>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QTextCodec *linuxCodec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForTr(linuxCodec);
    QTextCodec::setCodecForCStrings(linuxCodec);
    QTextCodec::setCodecForLocale(linuxCodec);
    resize(800, 500); // <-- a modificar en el futuro para permitir opciones

    pdf = new PdfViewer(this);
    pdf->load(tr("/home/jjdelasheras/Descargas/bash.pdf"));
    setCentralWidget(pdf);
}
