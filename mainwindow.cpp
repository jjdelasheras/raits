#include "mainwindow.h"
#include <QTextCodec>
#include <QScrollArea>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QTextCodec *linuxCodec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForTr(linuxCodec);
    QTextCodec::setCodecForCStrings(linuxCodec);
    QTextCodec::setCodecForLocale(linuxCodec);
    resize(600, 600); // <-- a modificar en el futuro para permitir opciones

    QScrollArea* scroll = new QScrollArea(this);
    pdf = new Pdf(this);
    pdf->open(tr("/home/jjdelasheras/Descargas/bash.pdf"));
    pdf->load();
 //   pdf->visualize();
    scroll->setWidget(pdf);
    setCentralWidget(scroll);
}
