#ifndef QUGATE_H
#define QUGATE_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QWidget>

#include "GateFont.h"
#include "GateRectF.h"

/**
 * @brief represent circuit gate
 */
class BaseGate : public QObject, public QGraphicsItem
{
  Q_OBJECT
public:
  explicit BaseGate(const QString &name, const QRectF &gate_rect, QObject *parent = nullptr);
  virtual ~BaseGate();
  QRectF boundingRect() const;

public slots:
  // void test();

protected:
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget) override;
  virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
  void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
  QString m_name;
  QWidget *m_property_widget;
  QGraphicsProxyWidget *m_item;
  GateRectF m_gate_rect;
  static GateFont m_gate_font;
};

#endif // QUGATE_H
