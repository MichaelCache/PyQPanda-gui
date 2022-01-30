
#include <QDesktopWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

#include "CentralWidget.h"
#include "logger/Logger.h"

CentralWidget::CentralWidget(QWidget *parent)
    : QWidget(parent)
{
    createComponent();
    initLayout();
}

CentralWidget::~CentralWidget()
{
}

void CentralWidget::createComponent()
{
    m_circute_view = new QGraphicsView(this);
    m_circuit_scence = new CircuitScene();

    m_circute_view->setScene(m_circuit_scence);
    m_circute_view->setCacheMode(QGraphicsView::CacheBackground);
    // m_circute_view->setStyleSheet("padding: 0px; border: 0px;");

    // redirect qdebug to SingletonLogger
    qInstallMessageHandler(redirectMessageHandle);
}

void CentralWidget::initLayout()
{
    QVBoxLayout *main_layout = new QVBoxLayout();
    main_layout->addWidget(m_circute_view, 9);
    main_layout->addWidget(SingletonLogger::instance(), 1);
    setLayout(main_layout);
}
