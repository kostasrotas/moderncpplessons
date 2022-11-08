#include <iostream>
#include <list>

class Phone{
    std::string name;
    std::string tel;

public:

    Phone(std::string name,std::string tel):name(name),tel(tel){
        //std::cout<<"Phone created :"<<name<<","<<tel<<"\n"<<std::flush;
    }

    //Phone(Phone &&)=default;

    void print(){
        std::cout<<""<<name<<","<<tel<<"\n"<<std::flush;
    }

    void setTel(std::string newTel){
        tel=newTel;
    }

    ~Phone(){
        //std::cout<<"Phone deleted :"<<name<<","<<tel<<"\n"<<std::flush;
    }
};

std::list<Phone> phones;

void printPhones(){
    std::cout<<" Phones: "<<phones.size()<<"\n"<<std::flush;
    for (auto &p:phones){
        p.print();
    }
}

int main(){
    std::list<Phone>::iterator it;
    std::cout<<"*** Program Start\n"<<std::flush;
    std::cout<<"Add some phones\n"<<std::flush;
    phones.push_back(Phone("Mary","6668887"));
    phones.push_back(Phone("Giannis","66248887"));
    phones.push_back(Phone("Kostas","325553"));
    phones.push_back(Phone("Eleni","6629887"));
    printPhones();
    std::cout<<"Change 3rd phone Number. Delete 2nd phone and last one\n"<<std::flush;
    it= phones.begin();
    std::advance(it,2);
    it->setTel("555444332");
    it= phones.begin();
    std::advance(it,1);
    it->print();
    phones.erase(it);
    phones.pop_back();
    printPhones();
    std::cout<<"Insert in second position a new phone\n"<<std::flush;
    it= phones.begin();
    std::advance(it,1);
    phones.insert(it,Phone("Giorgos","65646344923"));
    printPhones();
    std::cout<<"*** Program End\n"<<std::flush;
}

