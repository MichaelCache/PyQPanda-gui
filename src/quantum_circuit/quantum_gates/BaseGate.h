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
  void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

  void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;

private:
  QString m_name;              // also will be gate name drawed in gate rectanguler block
  GateRectF m_gate_rect;       // gate rectanguler block with color
  static GateFont m_gate_font; // gate name font type and color in gate rectanguler block
};

#endif // QUGATE_H
