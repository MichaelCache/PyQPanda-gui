#ifndef QUGATE_H
#define QUGATE_H

#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QObject>
#include <QWidget>
#include <QMenu>

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

private slots:
  void setDagger();
  void deleteSelf();

public slots:
  void isInValidPos(bool, QPointF);

signals:
  void showValidPos(QRectF);
  void hideValidPos();
  void checkValidPos(QRectF);
  void occupyPos(bool);

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
};

#endif // QUGATE_H
