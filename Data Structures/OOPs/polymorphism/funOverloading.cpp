//we will study function overloading from here:

#include <bits/stdc++.h>
using namespace std;

class ApnaCollege
{
    public:
    void fun(){
        cout<<"fun called with no argument\n";
    }
    void fun(int x){
        cout<<"fun called with "<<x<<" argument\n";
    }
    void fun(int x,double y){
        cout<<"fun called with "<<x<<" and "<<y<<" argument\n";
    }
};
int main(){
    ApnaCollege Adri;
    Adri.fun();
    Adri.fun(1);
    Adri.fun(2,3.4);
    return 0;
}