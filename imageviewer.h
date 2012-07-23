#ifndef VIEWER_H
#define VIEWER_H

#include <QWidget>
#include <QLabel>
#include <QScrollArea>
#include <QString>

class ImageViewer : public QWidget
{
    Q_OBJECT
private:
    QLabel* imageLabel;
    QScrollArea* scroll;
    double scaleFactor;

    void scaleImage(double factor);
    void adjustScrollBar(QScrollBar* scrollBar, double factor);

public:
    explicit ImageViewer(QWidget *parent = 0);
    void open(const QString& fileName);
    void zoomIn();
    void zoomOut();
    void normalSize();

    
};

#endif // VIEWER_H
