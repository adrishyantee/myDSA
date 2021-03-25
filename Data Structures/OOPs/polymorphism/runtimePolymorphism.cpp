#include <bits/stdc++.h>
using namespace std;

class base{
    public:
    virtual void print(){
        cout<<"this is the base class's print func"<<endl;
    }
    void display(){
        cout<<"this is the base class's display func"<<endl;
    }
};
class derived:public base{
    public:
    void print(){
        cout<<"this is the derived class's print func"<<endl;
    }
    void display(){
        cout<<"this is the derived class's display func"<<endl;
    }
};

int main(){
    base* baseptr;//always to be passed as pointer
    derived d;
    baseptr=&d;
    baseptr->print();//first moves to the member functions of base class if possible executes it
    baseptr->display();//if virtual keyword is found it is not displayed rather the func similar to it is executed
    

    derived a;
    a.print();
    a.display();
    
    return 0;
}