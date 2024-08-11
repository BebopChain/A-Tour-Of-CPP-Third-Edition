#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

void print1()
{
    while(true)
    {
        std::cout<<"1"<<std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void print2()
{
    while(true)
    {
        std::cout<<"2"<<std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

int main()
{
    std::cout<<"HELLO WORLD"<<std::endl;
    std::thread t1(print1);
    std::thread t2(print2);

    if(t1.joinable())
        t1.join();
    if(t2.joinable())
        t2.join();

    return 0;
}