
#ifndef PDF_H
#define PDF_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsLinearLayout>
#include <QGraphicsWidget>
#include <poppler/qt4/poppler-qt4.h>
#include <QVector>
#include <QString>

class QLabel;
class QSize;

class Pdf : public QGraphicsScene
{
    Q_OBJECT
private:
    Poppler::Document* m_document;
    QVector<QLabel*> m_pdf;
    QGraphicsLinearLayout* m_layout;
    QGraphicsWidget* m_widget;
    int m_currentPage;
    QSize m_parentSize;

    void renderPage(int _nPage);

public:
    explicit Pdf(QGraphicsView *parent = 0);
    Poppler::Document* getDocument() const;
    QLabel* getPage(int _nPage) const;
    QGraphicsWidget* widget() const;
    QSize size();
    bool open(const QString& _filename);
    void load();
    void setCurrentPage(int _nPage);
    void scalePdf(QSize _newSize);
    void fitWidth(int _nPage);
    int getCurrentPage();
    int numPages();

    
signals:
    
public slots:
    
};

#endif // PDF_H
