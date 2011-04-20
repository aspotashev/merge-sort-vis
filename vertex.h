#ifndef BALL_H
#define BALL_H

#include <QtGui>

class Vertex : public QGraphicsItem
{
public:
    Vertex(QPointF pos, std::vector<int> values);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    qreal yPos() const;
    QPointF bottomPoint() const;
    QPointF topPoint() const;

private:
    QPointF m_pos; // position of center
    std::vector<int> m_values;
};

#endif // BALL_H
