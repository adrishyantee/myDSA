#include <bits/stdc++.h> 
using namespace std;

int main()
{
    const long int M = 1000000007;
    int T;
    cin>>T;
    for(int test=0;test<T;test++){
        int m,p,m1,p1;
        long int n,a,c;
        cin>>n>>m>>p>>a>>c;
        long long int exp=0;
        long int B[m];
        long int D[p];
        int i=0,j=0;
        for(int i=0;i<m;i++){
            cin>>B[i];
        }
        for(int i=0;i<p;i++){
            cin>>D[i];
        }
        int sum = n*(n-1)/2;
        for(int  k=0;k<p;k++){
            for(int  j=0;j<m;j++){
                    // exp= (exp +((long long int)((B[j]D[k])(((n*(n+1)(2*n+1))/6)- (n(n+1) + n) )+ ((a* D[k]+ c*B[j])((n(n+1))/2)-n) + n*a*c))) % M;
                    exp = (exp + (a*n+sum*B[j])*(c*n+sum*D[k])) % M;
                }
        }
        cout<<(6*(long long int)(exp))% M<<endl;
    }
    return 0;
}
