#ifndef PDFVIEWER_H
#define PDFVIEWER_H

#include <QScrollArea>

class Pdf;
class QString;
class QScrollBar;
class QSize;

class PdfViewer : public QScrollArea
{
    Q_OBJECT
private:
    Pdf* m_pdf;
    QString m_filename;
    QSize m_originalSize;
    float m_scaleFactor;
    int m_currentPage;
    int m_numPages;

    void adjustScrollBar(QScrollBar* _scrollBar, float _factor);

public:
    explicit PdfViewer(QWidget *parent = 0);
    bool open(const QString& _filename);
    int numPages();
    int getCurrentPage();
    float getScaleFactor();
    Pdf* getPdf() const;
    const QString getFilename();
    void setFilename(const QString& _filename);
    void zoomIn();
    void zoomOut();
    void scalePdf(float _factor);
    void setCurrentPage(int _nPage);
    void selectText();

public slots:
    void fitPageWidth();

};

#endif // PDFVIEWER_H
