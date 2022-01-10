#include "MainWindow.h"

#include <QDesktopWidget>
#include <QLabel>
#include <QPushButton>
#include <QStyleFactory>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
  // max main window
  showMaximized();
  setStyle(QStyleFactory::create("fusion"));

  createComponent();
  initUi();
}

MainWindow::~MainWindow() {}

void MainWindow::createComponent()
{
  m_main_widget = new QWidget(this);
  m_circute_view = new QGraphicsView(m_main_widget);
  m_circuit_scence = new CircuitScene();

  m_circute_view->setScene(m_circuit_scence);
  m_circute_view->setCacheMode(QGraphicsView::CacheBackground);

  QRect& rcontent = m_circute_view->contentsRect();
  m_circute_view->setSceneRect(0, 0, rcontent.width(), rcontent.height());

  QLabel m_coord;

  setCentralWidget(m_main_widget);
}

void MainWindow::initUi()
{
  QVBoxLayout *main_layout = new QVBoxLayout();
  main_layout->addWidget(m_circute_view);
  m_main_widget->setLayout(main_layout);
}
