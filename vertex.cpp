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
    painter->drawRect(boundingRect());
    painter->drawText(boundingRect(), QString::number((int)m_values.size()));
}

QRectF Vertex::boundingRect() const
{
    return QRectF(
    	m_pos.x() - 15 * (int)m_values.size(), m_pos.y() - 15,
	30 * (int)values.size(), 30);
}
