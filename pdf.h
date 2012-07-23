#ifndef PDF_H
#define PDF_H

#include <QWidget>
#include <QVector>
#include <poppler/qt4/poppler-qt4.h>
#include <QImage>
#include <QVBoxLayout>

class QString;
class QLabel;

class Pdf : public QWidget
{
    Q_OBJECT
private:
    QString filename;
    Poppler::Document* document;
    QVector<QLabel *> images;
    QVBoxLayout* layout;

public:
    explicit Pdf(QWidget *parent = 0);
    void open(const QString& _filename);
    void load();
};

#endif // PDF_H
