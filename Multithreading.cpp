#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

std::mutex threadLock;

int counter = 0;

void Function()
{
    threadLock.lock();

    counter++;

    threadLock.unlock();
}

int main()
{
    std::thread thread1(Function);
    std::thread thread2(Function);
    std::thread thread3(Function);

    std::cout << counter<<std::endl;

    thread1.join();
    thread2.join();    
    thread3.join();

    std::cout << counter;

    return 0;
}