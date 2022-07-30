#include <bits/stdc++.h>
using namespace std;

int fact(int n){
    if (n == 0)
    return 1;
    else
    return n* fact(n-1);
}

int combo(int n,int r){
    int t1,t2,t3;
    t1=fact(n);
    t2=fact(n-r);
    t3=fact(r);
    return (t1/(t3*t2));
}

int main(){
    cout<<combo(4,2)<<endl;
}