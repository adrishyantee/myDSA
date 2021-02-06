#include <bits/stdc++.h> 
using namespace std;

int main()
{
const long M = 1000000007;
int T;
long m,p;
long long n,a,c,mm,pp,i=0,j=0;
cin>>T;
while(T>0){
cin>>n>>m>>p>>a>>c;
long long exp=0;
mm=m;
long long* B = new long long[m];
long long* D = new long long[p];

while(mm>0){
    cin>>B[i];
    i++;
    mm--;
}
pp=p;
while(pp>0){
    cin>>D[j];
    j++;
    pp--;
}
for(long long k=0;k<p;k++){
    for(long long j=0;j<m;j++){
        for(long long i=1;i<=n;i++){
            exp= exp + (((a%M+(B[j]*(i-1))%M)%M)*(c%M+(D[k]*(i-1))%M)%M)% M;
        }
    }
}
cout<<(6%M*exp)% M<<endl;
 delete[] B;
 delete[] D;
T--;
}
return 0;
}
