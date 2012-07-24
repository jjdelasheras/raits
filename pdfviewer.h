#ifndef PDFVIEWER_H
#define PDFVIEWER_H

#include <QWidget>
#include <QGridLayout>
#include <QScrollArea>
#include "pdf.h"

class PdfViewer : public QWidget
{
    Q_OBJECT
private:
    Pdf* pdf;
    QScrollArea* scroll;
    QGridLayout* layout;

public:
    explicit PdfViewer(QWidget *parent = 0);
    void load(const QString& filename);
    
signals:
    
public slots:
    
};

#endif // PDFVIEWER_H
