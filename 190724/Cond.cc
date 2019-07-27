#include <unistd.h>
#include <pthread.h>
#include <iostream>

using std::cout;
using std::endl;

class MutexLock
{
public:
    MutexLock()
        : _mutex()
    {
        pthread_mutex_init(&_mutex, NULL);
        cout << "mutex initialized" << endl;
    }
    
    MutexLock(const MutexLock & rhs) = delete;
	MutexLock & operator=(const MutexLock & rhs) = delete;

    void lock()
    {
        pthread_mutex_lock(&_mutex);
    }

    void unLock()
    {
        pthread_mutex_unlock(&_mutex);
    }

    pthread_mutex_t &getMutex()
    {
        return _mutex;
    }

    ~MutexLock()
    {
        pthread_mutex_destroy(&_mutex);
    }

private:
    pthread_mutex_t _mutex;
};

class MutexLockGuard
{
public:
    MutexLockGuard(MutexLock & mutex)
    : _mutex(mutex)
    {
        _mutex.lock();
    }

    ~MutexLockGuard()
    {
        _mutex.unLock();
    }

private:
    MutexLock & _mutex;
};

class Condition
{
public:
    Condition(MutexLock &mutex)
        : _cond(), _mutexInCond(mutex)
    {
        pthread_cond_init(&_cond, NULL);
        cout << "cond initialized" << endl;
    }
    Condition(const Condition & rhs) = delete;
	Condition & operator=(const Condition & rhs) = delete;
    void wait()
    {
        MutexLockGuard mutexGuard(_mutexInCond);
        pthread_cond_wait(&_cond, &_mutexInCond.getMutex());
    }

    void notify()
    {
        pthread_cond_signal(&_cond);
    }

    void notifyAll()
    {
        pthread_cond_broadcast(&_cond);
    }

    ~Condition()
    {
        pthread_cond_destroy(&_cond);
    }

private:
    pthread_cond_t _cond;
    MutexLock &_mutexInCond;
};

void *pthHandle(void *p)
{
    Condition *cond = static_cast<Condition *>(p);
    cond->wait();
    cout << "3 seconds passed" << endl;
}

int main(int argc, char **argv)
{
    MutexLock mutex;
    Condition cond(mutex);
    pthread_t pthid;
    pthread_create(&pthid, NULL, pthHandle, &cond);
    sleep(3);
    cond.notify();
    pthread_join(pthid, NULL);
    return 0;
}