#include <iostream>
#define M 1000000007
#define ll long long int
using namespace std;

int main() {
// your code goes here
int t;
cin>>t;
while(t--)
{

ll n,m,p,a,c,s,B=0,D=0,i;
cin>>n>>m>>p>>a>>c;

int x;
for(i=0;i<m;i++)
{
cin>>x;
B+=x;
}
for(i=0;i<p;i++)
{
cin>>x;
D+=x;
}

s=(m*n*p*a*c) + (((n*(n-1)*(2*n-1))/6)*B*D) + (n*(n-1)/2)*((m*a*D)+(p*c*B));

s=(6*s)%M;
cout<<s<<endl;
}
return 0;
}
