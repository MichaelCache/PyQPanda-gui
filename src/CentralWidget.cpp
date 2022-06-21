
#include <QDesktopWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

#include <QDateTime>
#include <QMouseEvent>

#include "CentralWidget.h"
#include "logger/Logger.h"

// static QString log_info;

// void redirectMessageHandle(QtMsgType type, const QMessageLogContext &context, const QString &str)
// {
//     QString message = QString("%1 %2:%3 %4")
//                           .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"))
//                           .arg(context.file)
//                           .arg(context.line)
//                           .arg(str);

//     log_info.append(message);
// }


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
    m_circuit_scence = new CircuitScene(this);
    m_logger = new QTextEdit(this);

    connect(&SingletonLogger::instance(),SIGNAL(log(const QString&)), m_logger, SLOT(append(const QString&)));

    m_circute_view->setScene(m_circuit_scence);
    m_circute_view->setCacheMode(QGraphicsView::CacheBackground);

    // redirect qdebug to SingletonLogger
    qInstallMessageHandler(redirectMessageHandle);
}

void CentralWidget::initLayout()
{
    QVBoxLayout *main_layout = new QVBoxLayout();
    
    main_layout->addWidget(m_circute_view, 9);
    main_layout->addWidget(m_logger, 1);
    setLayout(main_layout);
}
