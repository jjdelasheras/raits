#include "pdfviewer.h"
#include "pdf.h"
#include "auxfunctions.h"
#include <QString>
#include <QScrollBar>
#include <QDebug>


PdfViewer::PdfViewer(QWidget *parent) :
    QScrollArea(parent)
{
    m_pdf = new Pdf(this);
    m_scaleFactor = 1.0;
    resize(parent->size());
    setWidgetResizable(true);
    setAlignment(Qt::AlignCenter);
}

void PdfViewer::adjustScrollBar(QScrollBar *_scrollBar, float _factor)
{
    _scrollBar->setValue(int(_factor * _scrollBar->value()
                            + ((_factor - 1) * _scrollBar->pageStep()/2)));
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
    setWidget(m_pdf);

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
    m_scaleFactor *= 1.25;
    scalePdf(m_scaleFactor);
}

void PdfViewer::zoomOut()
{
    m_scaleFactor *= 0.8;
    scalePdf(m_scaleFactor);
}

void PdfViewer::scalePdf(float _factor)
{
    Q_ASSERT(imageLabel->pixmap());
        m_scaleFactor = _factor;
        m_pdf->scalePdf(m_scaleFactor);
        adjustScrollBar(horizontalScrollBar(), _factor);
        adjustScrollBar(verticalScrollBar(), _factor);
        // Falta codigo para activar y desactivar los menus segun llegue o no al zoom maximo - minimo
}

void PdfViewer::fitPageWidth()
{
    // Codigo que repinta cada vez que la pantalla es redimensionada si esta activado el fitPageWidth
}

void PdfViewer::setCurrentPage(int _nPage)
{
    m_currentPage = _nPage;
}

void PdfViewer::selectText()
{

}
