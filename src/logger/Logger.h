#pragma once

#include <QTextEdit>

void redirectMessageHandle(QtMsgType, const QMessageLogContext &, const QString &);

class SingletonLogger : public QTextEdit
{
    Q_OBJECT
public:
    static SingletonLogger* instance();

private:
    SingletonLogger(QWidget *parent = nullptr);
    ~SingletonLogger();
    static SingletonLogger* m_instance;
};