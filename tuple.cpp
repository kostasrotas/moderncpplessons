#include <tuple>
#include <iostream>
#include <cmath>

std::tuple<bool,float,float> solveTrionym(float a,float b,float c){
    float d,r1=0,r2=0;
    bool solutionFound;
    d=b*b-4*a*c;
    if (d<0)
        solutionFound=false;
    else{
        solutionFound=true;
        r1=(-b+sqrt(d))/(2*a);
        r1=(-b-sqrt(d))/(2*a);
    }
    return std::make_tuple(solutionFound,r1,r2);
}


int main()
{
    //std::tuple<bool,float,float> solution = solveTrionym(2,2,0);
    //std::tuple<bool,float,float> solution = solveTrionym(1,1,10);
    float a,b,c;
    std::cout<<"a=";
    std::cin>>a;
    std::cout<<"b=";
    std::cin>>b;
    std::cout<<"c=";
    std::cin>>c;
    //faster with auto
    auto [found,r1,r2] = solveTrionym(a,b,c);    
    //std::tuple<bool,float,float> solution = solveTrionym(a,b,c);
    //bool found = std::get<0>(solution);
    //float r1 = std::get<1>(solution);
    //float r2 = std::get<2>(solution);
    if (found)
        std::cout<<" Solutions:\nr1="<<r1<<"\nr2="<<r2<<"\n"<<std::flush;
    else
        std::cout<<" No Solutions\n"<<std::flush;
    return 0;
}

