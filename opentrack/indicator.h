#pragma once

#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QTimer>
#include <QPainter>

class IndicatorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit IndicatorWidget();

protected:
    void paintEvent(QPaintEvent* event) override;

public slots:
    void setPosition(int newX, int newY);

private:
    QPixmap image;
};
