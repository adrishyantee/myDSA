#include <bits/stdc++.h> 
using namespace std;

int main()
{
const long int M = 1000000007;
int T;
int m,p,m1,p1;
long int n,a,c;
long long int B[2*100000];
long long int D[2*100000];
cin>>T;
for(int test=0;test<T;test++){
cin>>n>>m>>p>>a>>c;
long long int exp=0;
int i=0,j=0;
 m1=m;
while(m1>0){
    cin>>B[i];
    i++;
    m1--;
}
p1=p;
while(p1>0){
    cin>>D[j];
    j++;
    p1--;
}
 
for(int k=0;k<p;k++){
    for(int j=0;j<m;j++){
            exp= exp +(((B[j]*D[k])*(((n*(n+1)*(2*n+1))/6)- 
			(n*(n+1) + n) )+ ((a* D[k]+ c*B[j])*((n*(n+1))/2)-n) + n*a*c)) % M;
        }
}
cout<<(6*(long long int)(exp))% M<<endl;
}
return 0;
}
