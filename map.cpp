#include <iostream>
#include <unordered_map>
//#include <map>


std::unordered_map<std::string, std::string> phones;
// unordered_map is faster than map but it consumes more ram
//std::map<std::string, std::string> phones;

void printPhones(){
    std::cout<<" Phones: "<<phones.size()<<"\n"<<std::flush;
    for (auto &p:phones){
        std::cout<<p.first<<","<<p.second<<"\n";
    }
}

int main(){
    std::cout<<"*** Program Start\n"<<std::flush;
    std::cout<<"Add some phones\n"<<std::flush;
    phones["Mary"]="6668887";
    phones["Giannis"]="66448882";
    phones["Kostas"]="325553";
    phones["Eleni"]="6629887";
    printPhones();
    std::cout<<"Change Kostas phone Number. Delete Giannis phone and Eleni\n"<<std::flush;
    phones["Kostas"]="555444332";
    std::cout<<"Giannis,"<<phones["Giannis"]<<"\n";
    phones.erase("Giannis");
    phones.erase("Eleni");
    printPhones();
    std::cout<<"Insert a new phone\n"<<std::flush;
    phones["Giorgos"]="65646344923";
    printPhones();
    std::cout<<"*** Program End\n"<<std::flush;
}

