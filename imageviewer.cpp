#include "imageviewer.h"
#include "auxfunctions.h"
#include <QPalette>
#include <QImage>
#include <QPixmap>
#include <QMessageBox>
#include <QScrollBar>
#include <QGridLayout>
#include <QPoint>
#include <QPainter>

ImageViewer::ImageViewer(QWidget *parent) :
    QWidget(parent)
{
    QGridLayout* layout = new QGridLayout(this);
    imageLabel = new QLabel(this);
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);

    scroll = new QScrollArea(this);
    scroll->setBackgroundRole(QPalette::Dark);
    scroll->setWidget(imageLabel);
    scroll->setWidgetResizable(true);


    layout->addWidget(scroll);
    setLayout(layout);
}

void ImageViewer::open(const QString& filename)
{
    if(!pixmap.load(filename)) {
        QMessageBox::information(this, tr("Error al cargar imagen"), tr("Error: No pudo cargarse la imagen %1").arg(tail(filename)));
        return;
    }
    imageLabel->setPixmap(pixmap);
    scaleFactor = 1.0;
    imageLabel->adjustSize();
}

void ImageViewer::scaleImage(double factor)
{
    Q_ASSERT(pixmap);
    scaleFactor *= factor;
    imageLabel->resize(scaleFactor * pixmap.size());

    adjustScrollBar(scroll->horizontalScrollBar(), factor);
    adjustScrollBar(scroll->verticalScrollBar(), factor);
}

void ImageViewer::adjustScrollBar(QScrollBar *scrollBar, double factor)
{
    scrollBar->setValue(int(factor * scrollBar->value() + ((factor - 1) * scrollBar->pageStep()/2)));
}

void ImageViewer::zoomIn()
{
    scaleImage(1.25);
}

void ImageViewer::zoomOut()
{
    scaleImage(0.8);
}

void ImageViewer::normalSize()
{
    imageLabel->adjustSize();
    scaleFactor = 1.0;
}
