// future example
#include <iostream>       // std::cout
#include <future>         // std::future, std::promise, std::async 
#include <chrono>         // std::chrono::milliseconds

constexpr int checkNum=444444443;

bool is_prime (int x) {// a non-optimized way of checking for prime numbers
  for (int i=2; i<x; ++i)
    if (x%i==0) return false;
  return true;
}

int main ()
{
  std::promise<bool> p;
  std::future<bool> fut = p.get_future();
  std::thread ([&p](){p.set_value_at_thread_exit(is_prime(checkNum));}).detach();
    
  //can also use std::future with std::async (without std::promise)
  //std::future<bool> fut = std::async (is_prime,checkNum);
  
  std::cout << "checking, please wait"<<std::flush;
  while (fut.wait_for( std::chrono::milliseconds (100) )==std::future_status::timeout)
    std::cout << '.' << std::flush;
    
  bool x = fut.get();
  std::cout <<"\n "<< checkNum << (x?" is":" is not") << " prime.\n"<<std::flush;
  return 0;
}
