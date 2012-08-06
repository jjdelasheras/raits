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
    m_originalSize = m_pdf->size();
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
    float factorToScrollBar = _factor / m_scaleFactor;
    Q_ASSERT(m_pdf != 0);
        m_scaleFactor = _factor;
        m_pdf->scalePdf(m_scaleFactor * m_originalSize);
        adjustScrollBar(horizontalScrollBar(), factorToScrollBar);
        adjustScrollBar(verticalScrollBar(), factorToScrollBar);
        // Falta codigo para activar y desactivar los menus segun llegue o no al zoom maximo - minimo
}

void PdfViewer::fitPageWidth()
{
    for(int i = 0; i < m_pdf->numPages(); ++i)
        m_pdf->fitWidth(i);
}

void PdfViewer::setCurrentPage(int _nPage)
{
    m_currentPage = _nPage;
}

void PdfViewer::selectText()
{

}
