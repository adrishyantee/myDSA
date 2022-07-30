#include <iostream>
using namespace std;

class A{
    public:
    void func(){
        cout<<"Inherited";
    }
};
class B:public A{//accessing all the protected and public members of class A as public members of class B
};

int main(){
    B b; 
    b.func();
}