#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread> 
#include <chrono>

std::mutex mtx;
std::condition_variable cv;

void function1(){
    std::unique_lock<std::mutex> lck(mtx);
    std::cout << "Start function1\n" << std::flush;   
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); 
    std::cout << "function1 now waits....\n" << std::flush;
    cv.wait(lck);
    std::cout << "function1 goes on....\n" << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(1200));
    std::cout << "function1 finished\n" << std::flush;
}

void function2(){
    std::cout << "Start function2\n" << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout << "function2 notify\n" << std::flush;
    cv.notify_one();
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    std::cout << "function2 finished\n" << std::flush;
}

int main(){
  std::cout << std::endl;
  std::thread t1(function1);
  std::thread t2(function2);
  t1.join();
  t2.join();
  std::cout << std::endl;
}
