#include "vertex.h"

Vertex::Vertex(QPointF pos, std::vector<int> values)
{
    m_pos = pos;
    m_values = values;
}

void Vertex::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

//    painter->setBrush(QBrush());
//    painter->setPen(m_color.lighter());

    for (int i = 0; i < (int)m_values.size(); i ++)
    {
        QRectF rect(m_pos.x() - 15 * (int)m_values.size() + 15 * i, m_pos.y() - 15, 30, 30);
        painter->drawRect(rect);
        painter->drawText(rect, Qt::AlignCenter, QString::number(m_values[i]));
    }
}

QRectF Vertex::boundingRect() const
{
    return QRectF(
    	m_pos.x() - 15 * (int)m_values.size(), m_pos.y() - 15,
        30 * (int)m_values.size(), 30);
}
