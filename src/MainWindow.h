#pragma once

#include <QMainWindow>
#include <QWidget>

#include "quantum_circuit/CircuitScene.h"

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  void createComponent();
  void initUi();

  QWidget *m_main_widget;
  QGraphicsView *m_view;
  CircuitScene *m_cirruit_scence;
};