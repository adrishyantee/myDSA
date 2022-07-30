    
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int s=0,maxlen=0,count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
         
           s^= nums[i];
           if(s==k)
           count++;
           if(mp.find(s^k)!=mp.end()){
            count+=mp[s-k];
           }
           mp[s]++;
        }
        return count;// Your code here 
    }
    