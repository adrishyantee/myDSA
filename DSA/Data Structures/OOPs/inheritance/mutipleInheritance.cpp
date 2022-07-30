#include <iostream>
using namespace std;

class A{
    public:
    void Afunc(){
        cout<<"Inherited A\n";
    }
};
class B{
    public:
    void Bfunc(){
        cout<<"Inherited B\n";
    }
};
class C:public A,public B{//accessing all the protected and public members of class A and B as public members of class C
};

int main(){
    C c; 
    c.Afunc();
    c.Bfunc();
    return 0;
}