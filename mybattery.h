#ifndef MYBATTERY_H
#define MYBATTERY_H

#include <QWidget>
#include <QPainter>
#include <QPointF>
#include <QRectF>
#include <QBrush>
#include <QColor>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class MyBattery;
}
QT_END_NAMESPACE

class MyBattery : public QWidget
{
    Q_OBJECT

public:
    MyBattery(QWidget *parent = nullptr);
    ~MyBattery();

private:
    Ui::MyBattery *ui;

    void drawBorder( QPainter *painter);

    void drawBackGround(QPainter *painter);

    void drawHead( QPainter *painter);


    qreal m_borderRadius = 10.0;
    qreal m_thickness = 4.0;//电池矩形
    QRectF m_batteryRect;//电池矩形

    qint32 m_value = 50;
    qint32 m_currentValue = 0;
    qint32 m_alarmValue = 30;
    qint32 m_minValue = 0;
    qint32 m_maxValue = 100;
    qint32 m_margin = 6;
    qreal m_bgRadius = 6.0;
    qreal m_headRadius = 2.0;

    QColor m_normalColorStart;
    QColor m_normalColorEnd;
    QColor m_alarmColorStart;
    QColor m_alarmColorEnd;

    QBrush m_BorderBrush;


    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event) override;
private slots:
    void on_horizontalSlider_valueChanged(int value);
};
#endif // MYBATTERY_H
