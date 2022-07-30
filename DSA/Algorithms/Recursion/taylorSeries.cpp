#include <bits/stdc++.h>
using namespace std;

//using ordinary recursive call of e^x
int taylor(int x,int n)
{
static int p=1,f=1;
int r;
if (n==0)
return 1;
else{
    r=taylor(x,n-1);//recursive call
    p=p*x;
    f=f*n;
    return r+p/f;
}
}

//using Horner's Rule
int taylorHorner(int x,int n){
    static int s=1;
    if(n==0)
    return s;
    else{
    s= s+(x/n)*s;
    return taylorHorner(x,n-1);
    }
}
int main(){
    cout<<taylorHorner(9,2)<<endl;
    cout<<taylor(9,2);
    return 0;
}