#include "pdfviewer.h"

PdfViewer::PdfViewer(QWidget *parent) :
    QWidget(parent)
{
    pdf = new Pdf(this);
    scroll = new QScrollArea(this);
    scroll->setWidget(pdf);

}

void PdfViewer::load(const QString &filename)
{
    pdf->open(filename);
    pdf->load();
}
