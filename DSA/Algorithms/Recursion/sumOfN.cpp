#include <bits/stdc++.h> 
using namespace std; 

int sum(int n){
    static int s=0;
    if (n==0)
    return 0;
    s = n + sum (n-1);
    return s;
}
int main(){
    cout<<sum (3)<<endl;
    return 0;
}