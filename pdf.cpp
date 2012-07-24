#include "pdf.h"
#include <QString>
#include <QImage>
#include <QDebug>
#include <QSizePolicy>
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>

Pdf::Pdf(QWidget *parent) :
    QWidget(parent)
{
    document = 0;
    layout = new QVBoxLayout(this);
    setLayout(layout);
}

void Pdf::open(const QString& _filename)
{
    filename = _filename;

    document = Poppler::Document::load(filename);
    if(!document || document->isLocked())   {
        qDebug("Error: No se pudo abrir el pdf indicado.");
        delete document;
        return;
    }
}

void Pdf::load()
{
    QImage image;
    Poppler::Page* pdfPage;

    for(int nPage = 0;nPage < document->numPages();++nPage) {
        pdfPage = document->page(nPage);
        image = pdfPage->renderToImage();
        if(image.isNull())  {
            qDebug("Error: No se puede renderizar la página.");
            return;
        }
        images.push_back(new QLabel());
        images[nPage]->setPixmap(QPixmap::fromImage(image));
        layout->addWidget(images[nPage]);
    }
    delete pdfPage;
}
