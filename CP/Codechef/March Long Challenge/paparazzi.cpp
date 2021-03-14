#include <bits/stdc++.h>
using namespace std;

int main(){
int T;
cin>>T;
while(T--){
    int N;
    cin>>N;
    vector<pair<int,int>> p,heights;
    for(int i=0;i<N;i++){
    int H;cin>>H;
    p.push_back({i+1,H});
    }

    if (N==2){
    cout<<"1"<<endl;
    continue;
    }
    
    heights.push_back(p[0]);
    heights.push_back(p[1]);
    int ans=1,sz=heights.size();
    for(int i=2;i<N;i++){
    while(heights.size()>=2){//calc slope
        double s1=((double)heights[sz-1].second - (double)heights[sz-2].second)/((double)heights[sz-1].first-(double)heights[sz-2].first);
        double s2=((double)p[i].second - (double)heights[sz-1].second)/((double)p[i].first-(double)heights[sz-1].first);
        
        if (s1<=s2){
            heights.pop_back();
            sz--;
        }
        else
        break;
    }
    heights.push_back(p[i]);
    sz++;
    ans=max(ans,heights[sz-1].first-heights[sz-2].first);
    }
    cout<<ans<<endl;
}
return 0;
}
