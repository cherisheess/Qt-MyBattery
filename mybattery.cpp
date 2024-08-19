#include "mybattery.h"
#include "ui_mybattery.h"

MyBattery::MyBattery(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyBattery)
{
    ui->setupUi(this);
    m_currentValue = ui->horizontalSlider->value() + 10;
    m_normalColorStart = QColor(0, 0xEE, 0x00);
    m_normalColorEnd = QColor(0, 0xCD, 0x00);
    m_alarmColorStart = QColor(0xFF, 0x45, 0x00);
    m_alarmColorEnd = QColor(0xFF, 0x00, 0x00);

    m_BorderBrush.setColor(Qt::gray);
    m_BorderBrush.setStyle(Qt::SolidPattern); // 设置样式为实心

}

MyBattery::~MyBattery()
{
    delete ui;
}

void MyBattery::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

    //绘制边框
    drawBorder(&painter);

    //绘制背景
    drawBackGround(&painter);

    //绘制头部
    drawHead(&painter);

    this->update();
}

void MyBattery::drawBorder( QPainter *painter)
{
    painter->save();

    //绘制电池边框
    QPointF topLeft(ui->widget->x(),ui->widget->y());
    QPointF bottomRight(ui->widget->x() + ui->widget->width(),ui->widget->y() + ui->widget->height());
    m_batteryRect = QRectF(topLeft,bottomRight);

    painter->setPen(QPen(m_BorderBrush,m_thickness));
    painter->setBrush(Qt::NoBrush);
    painter->drawRoundedRect(m_batteryRect,m_borderRadius,m_borderRadius);

    painter->restore();
}

void MyBattery::drawBackGround(QPainter *painter)
{
    if(m_currentValue == m_minValue)
    {
        return;
    }

    painter->save();

    QLinearGradient batteryGradient(QPointF(0,0),QPointF(0,ui->widget->height()));
    if(m_currentValue <= m_alarmValue){
        batteryGradient.setColorAt(0.0,m_alarmColorStart);
        batteryGradient.setColorAt(1.0,m_alarmColorEnd);
    }else{
        batteryGradient.setColorAt(0.0,m_normalColorStart);
        batteryGradient.setColorAt(1.0,m_normalColorEnd);
    }

    double unit = (m_batteryRect.width() - (m_margin * 2)) /100;
    double width = m_currentValue *unit;
    QPointF topLeft(m_batteryRect.topLeft().x()+ m_margin, m_batteryRect.topLeft().y() + m_margin);
    QPointF bottomRight(m_batteryRect.bottomLeft().x() + width + unit + m_margin,
                        m_batteryRect.bottomLeft().y() - m_margin);
    QRectF rect(topLeft,bottomRight);

    painter->setPen(Qt::NoPen);
    painter->setBrush(batteryGradient);
    painter->drawRoundedRect(rect,m_bgRadius,m_bgRadius);

    painter->restore();
}

void MyBattery::drawHead(QPainter *painter)
{
    painter->save();

    double headWidth = m_batteryRect.width() / 15;

    QPointF headRectTopLeft(m_batteryRect.topRight().x(),
                            m_batteryRect.topRight().y() + m_batteryRect.height()/4);
    QPointF headRectBottomRight(m_batteryRect.topRight().x() + headWidth,
                                m_batteryRect.topRight().y() + m_batteryRect.height() /4 * 3);

    QRectF headRect(headRectTopLeft,headRectBottomRight);
    QLinearGradient headRectGradient(headRect.topLeft(),headRect.bottomLeft());
    headRectGradient.setColorAt(0.0,Qt::gray);
    headRectGradient.setColorAt(1.0,Qt::gray);

    painter->setPen(Qt::NoPen);
    painter->setBrush(headRectGradient);
    painter->drawRoundedRect(headRect,m_headRadius,m_headRadius);

    painter->restore();
}


void MyBattery::on_horizontalSlider_valueChanged(int value)
{
    m_currentValue = value;
}

