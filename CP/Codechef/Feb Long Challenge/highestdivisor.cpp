#include <bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin>>a;
    for(int i = 10;i>=1; i--)
    {
        if(a%i==0){
        cout<<i<<endl;
        break;
        }
    }
    return 0;
}