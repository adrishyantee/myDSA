//Not solved

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while (T--){

int R,C,X;
cin>>R>>C>>X;
int A[R][C], B[R][C],diff[R][C];;
for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
        cin>>A[i][j];
    }
}
for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
        cin>>B[i][j];
        diff[i][j]=B[i][j]-A[i][j];
    }
}

for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
        if(diff[i][j]==0)
        continue;
        else
        for(int k=0;k<X;k++){
        if(A[i][j+k]!=B[i][j+k])
            A[i][j+k]+=diff[i][j];
        else
            A[i+k][j]+=diff[i][j];

        }
    }
}
int c=0;
for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
        if(A[i][j]==B[i][j])
        c++;
}
}
if(c==R+C)
cout<<"Yes"<<endl;
else
cout<<"No"<<endl;   
    }
    return 0;
}