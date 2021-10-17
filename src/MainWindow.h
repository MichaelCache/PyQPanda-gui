#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>

#include "quantum_circuit/CircuitScence.h"

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
  CircuitScence *m_cirruit_scence;
};
#endif // MAINWINDOW_H
