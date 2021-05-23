#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        int G;
        cin>>G;
    int sum=0,count=0;
        for(int i=1;i<=G;i++){
            int sum=i;
            int j=1;
            while(j>0){
                if(sum==G){
                count++;
                break;
                }
                if(sum>G)
                break;
                sum+=(j+i);
                j++;
            }
        }
        cout<<"Case #"<<t<<":"<<count<<endl;
    }
    return 0;
}