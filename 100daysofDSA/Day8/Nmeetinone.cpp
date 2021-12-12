static bool comparator(pair<pair<int,int>,int>  m1, pair<pair<int,int>,int>  m2) 
    { 
    if (m1.first.second < m2.first.second) return true; 
    else if(m1.first.second > m2.first.second) return false; 
    else if(m1.second < m2.second) return true; 
    return false; 
   } 
   
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<pair<int,int>, int>> v;
        for(int i=0;i< n;i++){
            v.push_back({{start[i],end[i]},i+1});
        }
        
        sort(v.begin(),v.end(),comparator);
        
        int count=1,prevendtime=v[0].first.second;
    
        for(int i = 1;i<n;i++) {
            if(v[i].first.first > prevendtime) {
                prevendtime = v[i].first.second; 
                count++;
            }
        }
    return count;
    }
};