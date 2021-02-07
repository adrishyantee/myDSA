#include <bits/stdc++.h> 
using namespace std;

int main()
{
const long M = 1000000007;
int T;
long m,p,m1,p1;
long  n,a,c,i=0,j=0;
cin>>T;
for(int test=0;test<T;test++){
cin>>n>>m>>p>>a>>c;
long long exp=0;
 long B[m];
 long D[p];

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


 
for(long  k=0;k<p;k++){
    for(long  j=0;j<m;j++){
            exp= exp +((B[j]*D[k])*(((n*(n+1)*(2*n+6))/6)- 
			(n*(n+1) + n) )+ ((a* D[k] + c*B[j])*((n*(n+1))/2)-n)+a*c);
        }
}
cout<<((6% M) * (exp% M))% M<<endl;
 delete[] B;
 delete[] D;
}
return 0;
}
