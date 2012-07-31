
#ifndef PDF_H
#define PDF_H

#include <QWidget>
#include <QVector>
#include <QString>
#include <poppler/qt4/poppler-qt4.h>
#include <QVBoxLayout>

class QLabel;

class Pdf : public QWidget
{
    Q_OBJECT
private:
    Poppler::Document* m_document;
    QVector<QLabel*> m_pdf;
    int m_currentPage;
    QVBoxLayout* layout;

    void renderPage(int _nPage);

public:
    explicit Pdf(QWidget *parent = 0);
    Poppler::Document* getDocument() const;
    QLabel* getPage(int _nPage) const;
    bool open(const QString& _filename);
    void load();
    void setCurrentPage(int _nPage);
    void scalePdf(float _zoom);
    void fitWidth();
    int getCurrentPage();
    int numPages();

    
signals:
    
public slots:
    
};

#endif // PDF_H
