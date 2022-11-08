#include<iostream>
#include<set>
#include<string>

std::set<std::string> setOfStudents;

void printStudents(){
std::cout<<"Students:"<<setOfStudents.size()<<"\n";
for (auto &s:setOfStudents)
    std::cout<<" "<<s<<"\n";
std::cout<<std::flush;
}

int main()
{
    std::cout<<"Add Some Students"<<"\n";
    setOfStudents.insert("Kostas");
    setOfStudents.insert("Giannis");
    setOfStudents.insert("Maria");
    setOfStudents.insert("Eleni");
    printStudents();
    std::cout<<"Delete Giannis"<<"\n";
    setOfStudents.erase("Giannis");
    printStudents();
    return 0;
}

