#include "pdfviewer.h"
#include "pdf.h"
#include "auxfunctions.h"
#include <QString>
#include <QScrollBar>
#include <QDebug>


PdfViewer::PdfViewer(QWidget *parent) :
    QGraphicsView(parent)
{
    m_pdf = new Pdf(this);
    m_scaleFactor = 1.0;
    setAlignment(Qt::AlignCenter);
    setBackgroundBrush(Qt::lightGray);
    setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::HighQualityAntialiasing);
}

bool PdfViewer::open(const QString& _filename)
{
    m_filename = _filename;
    if(!m_pdf->open(_filename)) {
        qDebug() <<"No se pudo abrir el archivo: " <<tail(_filename);
        return false;
    }
    m_pdf->load();

    m_numPages = m_pdf->numPages();
    m_currentPage = 0;
    setScene(m_pdf);

    return true;
}

int PdfViewer::numPages()
{
    return m_numPages;
}

float PdfViewer::getScaleFactor()
{
    return m_scaleFactor;
}

Pdf* PdfViewer::getPdf() const
{
    return m_pdf;
}

const QString PdfViewer::getFilename()
{
    return m_filename;
}

void PdfViewer::setFilename(const QString& _filename)
{
    m_filename = _filename;
}

void PdfViewer::zoomIn()
{
    if(m_scaleFactor < 0.7)
        scalePdf(m_scaleFactor + 0.2);

    else if(m_scaleFactor < 1)
        scalePdf(m_scaleFactor + 0.15);

    else if(m_scaleFactor < 2)
        scalePdf(m_scaleFactor + 0.25);

    else if(m_scaleFactor < 4)
       scalePdf(m_scaleFactor + 1);
}

void PdfViewer::zoomOut()
{
    if(2 < m_scaleFactor)
        scalePdf(m_scaleFactor - 1);

    else if(1 < m_scaleFactor)
        scalePdf(m_scaleFactor - 0.25);

    else if(0.7 < m_scaleFactor)
        scalePdf(m_scaleFactor - 0.15);

    else if(0.5 < m_scaleFactor)
       scalePdf(m_scaleFactor - 0.2);
}

void PdfViewer::scalePdf(float _factor)
{
    float zoom = _factor / m_scaleFactor;
    scale(zoom, zoom);
}

void PdfViewer::fitPageWidth()
{
    // Si hay un bug al usar esta función después de usar algún zoom
    // es debido a que no se tiene en cuenta dicho zoom y se redimensiona
    // como si m_scaleFactor fuera 1.0
    qDebug() <<m_pdf->size();
    float width = dynamic_cast<QWidget*>(parent())->geometry().width();

    float fact = (width - (width*0.0435)) / m_pdf->size().width();
    qDebug() <<fact;
    scale(fact, fact);
}

void PdfViewer::setCurrentPage(int _nPage)
{
    m_currentPage = _nPage;
}

void PdfViewer::selectText()
{

}
