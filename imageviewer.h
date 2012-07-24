#ifndef VIEWER_H
#define VIEWER_H

#include <QWidget>
#include <QLabel>
#include <QScrollArea>
#include <QString>
#include <QResizeEvent>
#include <QPaintEvent>
#include <QPixmap>

class ImageViewer : public QWidget
{
    Q_OBJECT

protected:
//    void resizeEvent(QResizeEvent* event);
//    void paintEvent(QPaintEvent* event);

private:
    QLabel* imageLabel;
    QPixmap pixmap;
    QScrollArea* scroll;
    double scaleFactor;
    QSize widgetSize;

//    void autoScale(QSize _size);
    void scaleImage(double factor);
    void adjustScrollBar(QScrollBar* scrollBar, double factor);

public:
    explicit ImageViewer(QWidget *parent = 0);
    void open(const QString& fileName);
    void zoomIn();
    void zoomOut();
    void normalSize();
//    QSize sizeSC();

    
};

#endif // VIEWER_H
