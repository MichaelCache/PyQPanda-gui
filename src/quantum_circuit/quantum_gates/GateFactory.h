#include <QString>
#include <QWidget>
#include <QGraphicsRectItem>

// #include "../GateType.h"
#include "BaseGate.h"

class GateFactory : public QObject, public QGraphicsItem
{
public:
    explicit GateFactory(const QString &gate, QObject *parent = nullptr);
    virtual ~GateFactory();
    QRectF boundingRect() const;
    BaseGate *createGate();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QString m_gate_type;
    QPixmap m_gate_img;
};