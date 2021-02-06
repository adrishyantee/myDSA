#include <bits/stdc++.h> 
using namespace std;
unsigned long long factorial(int n)
{
    const unsigned int M = 1000000007;
 
    unsigned long long f = 1;
    for (int i = 1; i <= n; i++)
        f = (f*i) % M;  
    return f;
}
  
int main () 
{ 
    int q,l,r,queries;
    long long Fi=0,Fs=0;
    cin>>queries;
    q=queries;
    while (queries>0)
    {
        cin>>l>>r;
        queries--;
    }
    while(q>0)
    {
    for (int i=l;i<=r;i++)
    { 
       Fi =factorial(i)*factorial(i);
       Fs= Fi + Fs ;
    }
    
    cout<<Fs;
     q--;
    }
    return 0; 
} 