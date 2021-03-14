#include <bits/stdc++.h>
using namespace std;
//POSITION STARTS FROM 0
int fibo(int n){
    if(n<=1)
    return n;
    else
    return fibo(n-1)+fibo(n-2);
}

int main(){
    cout<<fibo(4)<<endl;;
    return 0;
}