#include <bits/stdc++.h>
using namespace std;

//USING PASCAL'S TRIANGLE
int pascal(int n, int r){
    if(r <=0 || r==n)
    return 1;
    else
    return pascal(n-1,r-1)+pascal(n-1,r);
}

int main(){
cout<<pascal(4,2)<<endl;
return 0;
}