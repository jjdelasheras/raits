#include "pdf.h"
#include <QString>
#include <QImage>
#include <QDebug>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>

Pdf::Pdf(QWidget *parent) :
    QWidget(parent)
{
    document = 0;
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
        pages.images.push_back(new QLabel());
        pages.scroll.push_back(new QScrollArea());

        pages.images[nPage]->setPixmap(QPixmap::fromImage(image));
        pages.scroll[nPage]->setWidget(pages.images[nPage]);
    }
    delete pdfPage;
}

void Pdf::visualize()
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    for(int i = 0;i < 5;++i)
        layout->addWidget(pages.scroll[i]);
    setLayout(layout);

}

void Pdf::close(){}
