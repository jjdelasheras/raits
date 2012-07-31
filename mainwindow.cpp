#include "mainwindow.h"
#include <QTextCodec>
#include <QScrollArea>
#include <pdf.h>
#include <QDebug>
#include <poppler/qt4/poppler-qt4.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QTextCodec *linuxCodec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForTr(linuxCodec);
    QTextCodec::setCodecForCStrings(linuxCodec);
    QTextCodec::setCodecForLocale(linuxCodec);
    resize(1000, 500); // <-- a modificar en el futuro para permitir opciones

    pdf = new PdfViewer(this);
    pdf->open("/home/jjdelasheras/Descargas/bash.pdf");
    setCentralWidget(pdf);
}
