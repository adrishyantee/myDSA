#include <iostream>
using namespace std;

int main ()
{
    
int n,t,c=0,total=0;
cin>>n>>t;
int time = 4*60 -t;
    for(int i=1;i<=n;i++)
    {
    total = total + (5*i); 
    if(total<= time)
    c++;
    }
    cout<<c<<endl;
    return 0;
}
