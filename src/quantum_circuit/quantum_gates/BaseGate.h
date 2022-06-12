#ifndef QUGATE_H
#define QUGATE_H

#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QObject>
#include <QWidget>
#include <QMenu>
#include <QGraphicsObject>

#include "GateFont.h"
#include "GateRectF.h"

/**
 * @brief represent circuit gate
 */
class BaseGate : public QGraphicsObject
{
  Q_OBJECT
public:
  explicit BaseGate(const QString &name, const QPointF& pos, const QRectF &gate_rect, QGraphicsItem *parent = nullptr);
  virtual ~BaseGate();
  QRectF boundingRect() const;
  const GateRectF& gateBox() const;

private slots:
  void setDagger();
  void deleteSelf();

public slots:
  // void isInValidPos(bool, QPointF scene_pos);

signals:
  void showValidPos(BaseGate*);
  void hideValidPos();
  // void checkValidPos(QRectF scene_rect, BaseGate*);
  // void occupyPos(bool);
  // void connectDelete(BaseGate*);
  // void disconnectDelete(BaseGate*);
  void deleteGate(BaseGate*);

protected:
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget) override;
  void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
  // void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

  void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;

private:
  void initPropertyMenu();
  QString m_name;              // also will be gate name drawed in gate rectanguler block
  GateRectF m_gate_rect;       // gate rectanguler block with color
  static GateFont m_gate_font; // gate name font type and color in gate rectanguler block
  QMenu m_property_menu;
  QString m_dagger{0x2020}; // unicode dagger
  bool m_is_dagger{false};
  bool m_in_valid{false};
};

#endif // QUGATE_H
