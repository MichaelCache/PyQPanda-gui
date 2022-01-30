#pragma once

#include <QWidget>

#include "quantum_circuit/CircuitScene.h"

class CentralWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CentralWidget(QWidget *parent = nullptr);
    ~CentralWidget();

private:
    void createComponent();
    void initLayout();
    
    QGraphicsView *m_circute_view;
    CircuitScene *m_circuit_scence;
};
