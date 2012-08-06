#include "pdf.h"
#include "pdfviewer.h"
#include "auxfunctions.h"
#include <QDebug>
#include <QPixmap>
#include <QLabel>
#include <QImage>
#include <QSize>

Pdf::Pdf(QWidget *parent) :
    QWidget(parent)
{
    m_document = 0;
    m_layout = new QVBoxLayout(this);
    m_parentSize = parent->size();
    setLayout(m_layout);
}

// ********************************************************************
void Pdf::renderPage(int _nPage)
{
    PdfViewer* pv = dynamic_cast<PdfViewer*> (parent());
    float sf = pv->getScaleFactor();

    if(!m_document) {
        qDebug("No puede renderizarse la página ya que no se ha abierto ningún archivo");
        return;
    }
    QImage image = m_document->page(_nPage)->renderToImage(physicalDpiX(), physicalDpiY());

    m_pdf[_nPage]->setPixmap(QPixmap::fromImage(image));
    m_pdf[_nPage]->setScaledContents(true);
    m_pdf[_nPage]->setAlignment(Qt::AlignCenter);
}

// ********************************************************************
Poppler::Document* Pdf::getDocument() const
{
    return m_document;
}

// ********************************************************************
QSize Pdf::size()
{
    return m_pdf[0]->pixmap()->size();
}

// ********************************************************************
bool Pdf::open(const QString& _filename)
{
    m_document = Poppler::Document::load(_filename);
    m_document->setRenderHint(Poppler::Document::TextAntialiasing);

    if(m_document == 0) {
        qDebug() <<tr("No se ha podido cargar el archivo: ") <<tail(_filename);
        return false;
    }

    m_pdf.resize(m_document->numPages());
    for(int i = 0;i < m_document->numPages(); ++i)
        m_pdf[i] = new QLabel(this);

    return true;
}

// ********************************************************************
void Pdf::load()
{
    for(int i = 0; i < m_document->numPages(); ++i) {
        renderPage(i);
  //      m_pdf[i]->setScaledContents(true);
        m_layout->addWidget(m_pdf[i]);
    }
}

// ********************************************************************
void Pdf::setCurrentPage(int _nPage)
{
    m_currentPage = _nPage;
}
// ********************************************************************
void Pdf::scalePdf(QSize _newSize)
{    
    for(int i = 0;i < m_document->numPages(); ++i)
        m_pdf[i]->setPixmap(m_pdf[i]->pixmap()->scaled(_newSize) );
}

// ********************************************************************
void Pdf::fitWidth(int _nPage)
{
    m_pdf[_nPage]->setScaledContents(true);
}

// ********************************************************************
int Pdf::getCurrentPage()
{
    return m_currentPage;
}

// ********************************************************************
int Pdf::numPages()
{
    return m_pdf.size();
}

// ********************************************************************
QLabel* Pdf::getPage(int _nPage) const
{
    return m_pdf[_nPage];
}
