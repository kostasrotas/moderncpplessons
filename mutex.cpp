#include <iostream>
#include <thread>
#include <mutex>

// mutex.lock function
void function1(std::string functionName){
  static std::mutex mtx;
  mtx.lock();
  std::cout<<"Started function1 "<<functionName<<"\n"<<std::flush;
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  std::cout<<"Stopped function1 "<<functionName<<"\n"<<std::flush;
  mtx.unlock();
}

// unique_lock will unlock automatically (safer)
void function2(std::string functionName){
  static std::mutex mtx;
  std::unique_lock<std::mutex> lock(mtx); //or std::lock_guard<std::mutex> lock(mtx);
  std::cout<<"Started function2 "<<functionName<<"\n"<<std::flush;
  std::this_thread::sleep_for(std::chrono::milliseconds(1100));
  std::cout<<"Stopped function2 "<<functionName<<"\n"<<std::flush;
}

int main() {	
std::thread (function1,"f1").detach();
std::thread (function1,"f2").detach();
// std::thread can also be used with labda
std::thread ([](){
	function2("f3");
	}).detach();	
std::thread t4(function2,"f4");
t4.join();// wait t4 to finish and exit program
return 0;
}
