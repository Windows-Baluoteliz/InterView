//.h
#include <stdio.h>

class QMManager
{
protected:
    static QMManager instance_;
    QMManager();
    ~QMManager(){};
public:
    static QMManager *instance()
    {
        return &instance_;
    }
};
 
class QMSqlite
{
protected:
    static QMSqlite instance_;
    QMSqlite();
    ~QMSqlite(){};
public:
    static QMSqlite *instance()
    {
        return &instance_;
    }
    void do_something();
};
 
QMManager QMManager::instance_;
QMSqlite QMSqlite::instance_;

//.cpp
QMManager::QMManager()
{
    printf("QMManager constructor\n");
    QMSqlite::instance()->do_something();
}
 
QMSqlite::QMSqlite()
{
    printf("QMSqlite constructor\n");
}
void QMSqlite::do_something()
{
    printf("QMSqlite do_something\n");
}

int main()
{
    QMManager::instance();
    
    return 0;
}