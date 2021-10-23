#include "MainWindow.h"

#include <QDesktopWidget>
#include <QLabel>
#include <QPushButton>
#include <QStyleFactory>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  setStyle(QStyleFactory::create("fusion"));
  resize(QDesktopWidget().availableGeometry(this).size());

  createComponent();
  initUi();
}

MainWindow::~MainWindow() {}

void MainWindow::createComponent() {
  m_main_widget = new QWidget(this);
  m_view = new QGraphicsView(m_main_widget);
  m_cirruit_scence = new CircuitScene();

  m_view->setScene(m_cirruit_scence);
  m_view->setCacheMode(QGraphicsView::CacheBackground);

  QRect rcontent = m_view->contentsRect();
  m_view->setSceneRect(0, 0, rcontent.width(), rcontent.height());

  QLabel m_coord;

  setCentralWidget(m_main_widget);
}

void MainWindow::initUi() {
  QVBoxLayout *main_layout = new QVBoxLayout();
  main_layout->addWidget(m_view);
  m_main_widget->setLayout(main_layout);
}
