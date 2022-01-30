#include <QMutex>
#include <QDateTime>
#include <QMouseEvent>

#include "Logger.h"

SingletonLogger *SingletonLogger::m_instance;

SingletonLogger::SingletonLogger(QWidget *parent)
    : QTextEdit(parent)
{
    setMouseTracking(true);
}

SingletonLogger::~SingletonLogger()
{
}

SingletonLogger *SingletonLogger::instance()
{
    static QMutex mutex;
    QMutexLocker lock(&mutex);
    if (!m_instance)
    {
        m_instance = new SingletonLogger();
    }

    lock.unlock();
    return m_instance;
}

void redirectMessageHandle(QtMsgType type, const QMessageLogContext &context, const QString &str)
{
    SingletonLogger *logger = SingletonLogger::instance();
    QString message = QString("%1 %2:%3 %4")
                          .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"))
                          .arg(context.file)
                          .arg(context.line)
                          .arg(str);
    logger->append(message);
}
