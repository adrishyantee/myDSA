#include <bits/stdc++.h>
using namespace std;

class Complex{
    private:
    int real,img;
    public:
       Complex(int r=0,int i=0){
        real=r;
        img=i;
    }
    Complex operator + (Complex const &another){
        Complex res;
        res.real=real+another.real;
        res.img=img+another.img;
        return res;
    }
    void display(){
        cout<<real<<" + i"<<img<<endl;
    }
};

int main(){

    Complex c1(1,3);
    Complex c2(14,7);
    Complex c3=c1+c2;
    c3.display();
        return 0;
}