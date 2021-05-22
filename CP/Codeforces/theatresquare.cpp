#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,m,a;
    cin>>n>>m>>a;
    long long rem1=n%a;
    long long rem2=m%a;
    long long i=n/a;
    long long j=m/a;
    if(i!=0 && rem1>0)
    i++;
    if(j!=0 && rem2>0)
    j++;
    if(i==0)
    i++;
    if(j==0)
    j++;
    cout<<(i*j)<<endl;
    return 0;
}