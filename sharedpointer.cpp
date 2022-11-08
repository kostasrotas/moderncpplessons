#include <iostream>
#include <vector>
#include <memory>

class Phone{
    std::string name;
    std::string tel;

public:

    Phone(std::string name,std::string tel):name(name),tel(tel){
        std::cout<<"Phone created :"<<name<<","<<tel<<"\n"<<std::flush;
    }

    void print(){
        std::cout<<""<<name<<","<<tel<<"\n"<<std::flush;
    }

    void setTel(std::string newTel){
        tel=newTel;
    }

    ~Phone(){
        std::cout<<"Phone deleted :"<<name<<","<<tel<<"\n"<<std::flush;
    }
};

std::vector<std::shared_ptr<Phone>> phones;

void printPhones(){
    std::cout<<" Phones: "<<phones.size()<<"\n"<<std::flush;
    for (auto &p:phones){
        p->print();
    }
}

int main(){
    std::cout<<"*** Program Start\n"<<std::flush;
    std::cout<<"Add some phones\n"<<std::flush;
    phones.push_back((std::shared_ptr<Phone>) new Phone("Mary","6668887"));
    phones.push_back((std::shared_ptr<Phone>)new Phone("Giannis","66248887"));
    phones.push_back((std::shared_ptr<Phone>)new Phone("Kostas","325553"));
    phones.push_back((std::shared_ptr<Phone>)new Phone("Eleni","6629887"));
    printPhones();    
    std::cout<<"Change 3rd phone Number. Delete 2nd phone and last one\n"<<std::flush;
    phones[2]->setTel("555444332");
    phones[1]->print();
    phones.erase(phones.begin()+1);
    phones.pop_back();
    printPhones();
    std::cout<<"Insert in 2nd position a new phone\n"<<std::flush;
    phones.insert(phones.begin()+1,(std::shared_ptr<Phone>)new Phone("Giorgos","65646344923"));
    printPhones();
    std::cout<<"*** Program End\n"<<std::flush;
}

