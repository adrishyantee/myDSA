#include <bits/stdc++.h>
 using namespace std;

 int main(){
     int T;
     cin>>T;
     while(T--){
         int n;
         cin>>n;
         int sum=0;

        sum= (n/4)*44;

        int rem =(n%4);

        if(n>=4){
            if(rem==0)
            sum+=16;
            if(rem==1)
            sum+=32;
            if(rem==2)
            sum+=44;
            if(rem==3)
            sum+=55;
            cout<<sum<<endl;          
        }
        else{
            int res;
            if(rem==1){
                res=20;
            }
            if(rem==2){
                res=36;
            }
            if(rem==3){
                res=51;
            }
            cout<<res<<endl;
        }
    
     }
     return 0;
 }