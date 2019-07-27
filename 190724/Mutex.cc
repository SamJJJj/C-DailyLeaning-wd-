#include <pthread.h>
#include <iostream>

using std::cout;
using std::endl;

#define N 10000000

int num = 0;

class MutexLock
{
public:
    MutexLock()
    : _mutex()
    {
        pthread_mutex_init(&_mutex, NULL);
        cout << "mutex initialized" << endl;
    }

    void lock()
    {
        pthread_mutex_lock(&_mutex);
    }

    void unLock()
    {
        pthread_mutex_unlock(&_mutex);
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

void *
pthhandle(void *p)
{
    MutexLock *mutex = static_cast<MutexLock *>(p);
    int i;
    for (i = 0; i < N; ++i)
    {
        MutexLockGuard mutexGuard(*mutex);
        num++;
    }
}

int main(int argc, char **argv)
{
    MutexLock mutex;
    int i;
    pthread_t pthid;
    pthread_create(&pthid, NULL, pthhandle, &mutex);
    for (i = 0; i < N; i++)
    {
        MutexLockGuard mutexGuard(mutex);
        num++;
    }
    pthread_join(pthid, NULL);
    cout << "num = " << num << endl;
    return 0;
}