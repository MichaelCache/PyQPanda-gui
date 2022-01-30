#pragma once

#include <QMainWindow>

#include "CentralWidget.h"

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  CentralWidget *m_main_widget;
};