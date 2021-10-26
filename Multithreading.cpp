#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

std::mutex threadLock;
std::mutex unicLockMutex;

int firstcounter = 0;
int secondcounter = 0;

void MutexFunction()
{
    threadLock.lock();

    firstcounter++;

    threadLock.unlock();
}

void UniqueLockMutexFunction()
{
    std::unique_lock<std::mutex> unicLock(unicLockMutex);
    for (int i = 0; i < 10; i++)
    {
    secondcounter++;
    }
}

int main()
{
    std::thread thread1(MutexFunction);
    std::thread thread2(MutexFunction);
    std::thread thread3(MutexFunction);

    std::cout << firstcounter<<std::endl;

    thread1.join();
    thread2.join();    
    thread3.join();

    std::cout << firstcounter<<std::endl;

    std::thread unicthread1(UniqueLockMutexFunction);
    std::thread unicthread2(UniqueLockMutexFunction);

    std::cout << secondcounter<<std::endl;

    unicthread1.join();
    unicthread2.join();

    std::cout << secondcounter << std::endl;

    return 0;
}