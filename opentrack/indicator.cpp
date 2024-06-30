#include "indicator.h"
#include <Windows.h>


IndicatorWidget::IndicatorWidget()
{
    // 设置窗口置顶并使其不响应鼠标事件
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | Qt::WindowTransparentForInput);

    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_NoSystemBackground, false);

    // 加载图片
    image.load("indicator.png"); // 替换为你的图片路径
    resize(image.size());

    setVisible(false);
}

void IndicatorWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setCompositionMode(QPainter::CompositionMode_Source);
    painter.fillRect(rect(), Qt::transparent); // 填充透明背景
    // 绘制图像
    painter.drawPixmap(0, 0, image);
}

void IndicatorWidget::setPosition(int newX, int newY)
{
    if (newX == 0 && newY == 0) {
        if (isVisible())
            hide();
    }
    else
    {
        if (!isVisible())
            show();

        // 计算绘制图像的位置(居中显示)
        int xPos = (newX - image.width()) / 2;
        int yPos = (newY - image.height()) / 2;

        move(xPos, yPos);
    }
}
