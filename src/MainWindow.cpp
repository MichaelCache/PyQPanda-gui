#include <QStyleFactory>

#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
  setStyle(QStyleFactory::create("fusion"));

  m_main_widget = new CentralWidget(this);
  setCentralWidget(m_main_widget);
  
  // max main window
  showMaximized();
}

MainWindow::~MainWindow() {}
