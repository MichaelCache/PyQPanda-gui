#ifndef QUGATE_H
#define QUGATE_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QWidget>

class BaseGate : public QObject, public QGraphicsItem
{
  Q_OBJECT
public:
  explicit BaseGate(const QString &name, QObject *parent = nullptr);
  virtual ~BaseGate();
  QRectF boundingRect() const;

public slots:
  // void test();

protected:
  // void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
  // void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
  // void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
  QPixmap m_gate_img;
  QString m_name;
};

#endif // QUGATE_H
