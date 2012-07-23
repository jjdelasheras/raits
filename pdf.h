#ifndef PDF_H
#define PDF_H

#include <QWidget>
#include <QVector>
#include <poppler/qt4/poppler-qt4.h>
#include <QImage>
#include <QScrollArea>

class QString;
class QLabel;

class Pdf : public QWidget
{
    Q_OBJECT
private:
    QString filename;
    Poppler::Document* document;
    struct Images   {
        QVector<QLabel *> images;
        QVector<QScrollArea*> scroll;
    } pages;
public:
    explicit Pdf(QWidget *parent = 0);
    void open(const QString& _filename);
    void load();
    void visualize();
    void close();
    
};

#endif // PDF_H
