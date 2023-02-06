#include <iostream>
#include <functional>

int g(int x,int y){
    return x-y;
}

int main()
{
        int value = 1;
        std::function<int(int)> func1 = [value] (int param) -> int {return value+param;};     // pass by value
        std::function<int(int)> func2 = [&value] (int param) -> int {return value+param;};    // pass by ref
        auto func3 = [&](int param) ->int {return param+value;};                              // same as func2,using auto
        std::function<int(int)> func4 = std::bind(func2,std::placeholders::_1);               // using bind
        std::function<int(int)> func5 = std::bind(g,std::placeholders::_1,value);             // using g function
        std::function<int(int)> func6 = std::bind(g,value,std::placeholders::_1);             // usign g funciton, change args order
        value=2;
        std::cout << func1(2)<<"\n";// gives 3
        std::cout << func2(2)<<"\n";// gives 4
        std::cout << func3(2)<<"\n";// gives 4
        std::cout << func4(2)<<"\n";// gives 4
        std::cout << func5(2)<<"\n";// gives 1
        std::cout << func6(2)<<"\n";// gives -1
}

