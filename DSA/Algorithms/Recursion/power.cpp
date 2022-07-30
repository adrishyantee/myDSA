#include <bits/stdc++.h>
using namespace std;

int pow(int m,int n){
    if (n==0)
    return 1;
    else
    return pow(m,n-1)*m;
}

//more optimised solution
int pow1(int m,int n)
{
    if(n==0)
    return 1;
    if(n%2==0)
    return pow1(m*m , n/2);
    else
    return m*pow1(m*m,(n-1)/2);
}

int main()
{
    cout<<pow1(4,2);
    return 0;

}
