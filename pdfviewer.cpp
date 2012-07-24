#include "pdfviewer.h"
#include <QSizePolicy>
#include <QPalette>

PdfViewer::PdfViewer(QWidget *parent) :
    QWidget(parent)
{
    layout = new QGridLayout(this);
    pdf = new Pdf(this);
    scroll = new QScrollArea(this);

    scroll->setWidgetResizable(true);
    layout->addWidget(scroll);
    setLayout(layout);
}

void PdfViewer::load(const QString &filename)
{
    pdf->open(filename);
    pdf->load();
    scroll->setWidget(pdf);
}
