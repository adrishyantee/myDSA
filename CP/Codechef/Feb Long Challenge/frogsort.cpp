#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        int weight[n];
        for(int i=0;i<n;i++)
        cin>>weight[i];
        int jump[n];
        for(int i=0;i<n;i++)
        cin>>jump[i];
        map<int,pair<int,int>>m;
        for(int i=0;i<n;i++){
            m[weight[i]]={jump[i],i};
        }
        int answer=0;
        int current;
        for(auto it=m.begin();it!=m.end();it++){
            if(it==m.begin()){
                current=(it->second).second;
            }
            else{
                int index=(it->second).second;
                while(current>=index){
                    answer++;
                    index+=((it->second).first);
            
                }
                current=index;
            }
        }
        cout<<answer<<endl;
        t--;
    }
    return 0;
}