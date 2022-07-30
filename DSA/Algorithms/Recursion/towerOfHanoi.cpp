#include <bits/stdc++.h>
using namespace std;

void TowerofHanoi(int n, int A,int B,int C){
    if(n>0){
    TowerofHanoi(n-1,A,C,B);
    cout<<A<<" to "<< C <<endl;
    TowerofHanoi(n-1,B,A,C);
    }
}

int main(){
    TowerofHanoi(3,1,2,3);
    return 0;
}