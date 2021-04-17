#include <bits/stdc++.h>
#include <set>
using namespace std;

int main(){
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
    int n;
    cin>>n;
    int val;
    multiset<int>s;
    for(int i=0;i<n;i++){
        cin>>val;
        s.insert(val);
    }
    int max=0,k=0,sum=0;
    for(auto i:s){
        if(i>max){
        k++;
        max=i;
        }
        sum+=k;
    }
    cout<<"Case #"<<t<<": "<<sum<<endl;
    }
    return 0;
}