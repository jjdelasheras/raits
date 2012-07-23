#include "imageviewer.h"
#include <QPalette>
#include <QImage>
#include <QPixmap>
#include <QMessageBox>
#include <QScrollBar>
#include <QGridLayout>
#include "auxfunctions.h"

ImageViewer::ImageViewer(QWidget *parent) :
    QWidget(parent)
{
    QGridLayout* layout = new QGridLayout(this);
    imageLabel = new QLabel;
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    scroll = new QScrollArea;
    scroll->setBackgroundRole(QPalette::Dark);
    scroll->setWidget(imageLabel);

    layout->addWidget(scroll);
    setLayout(layout);
}

// *********************************************************************************
void ImageViewer::scaleImage(double factor)
{
    Q_ASSERT(imageLabel->pixmap());
    scaleFactor *= factor;
    imageLabel->resize(scaleFactor * imageLabel->pixmap()->size());

    adjustScrollBar(scroll->horizontalScrollBar(), factor);
    adjustScrollBar(scroll->verticalScrollBar(), factor);
}

// *********************************************************************************
void ImageViewer::adjustScrollBar(QScrollBar *scrollBar, double factor)
{
    scrollBar->setValue(int(factor * scrollBar->value() + ((factor - 1) * scrollBar->pageStep()/2)));
}

// *********************************************************************************
void ImageViewer::open(const QString& filename)
{
    QImage image(filename);
    if(image.isNull())  {
        QMessageBox::information(this, tr("Error"), tr("No ha podido cargarse: %1").arg(tail(filename)));
        return;
    }
    imageLabel->setPixmap(QPixmap::fromImage(image));
    scaleFactor = 1.0;

    imageLabel->adjustSize();
}

// *********************************************************************************
void ImageViewer::zoomIn()
{
    scaleImage(1.25);
}

// *********************************************************************************
void ImageViewer::zoomOut()
{
    scaleImage(0.8);
}

// *********************************************************************************
void ImageViewer::normalSize()
{
    imageLabel->adjustSize();
    scaleFactor = 1.0;
}
