class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int, int> mp;
        int s=0,maxlen=0;
        for(int i=0;i<n;i++){
          
           s+= A[i];
           if(s==0)
           maxlen=max(maxlen,i+1);
           else{
           if(mp.find(s)!=mp.end())
           maxlen=max(maxlen, (i-mp[s]));
           else
           mp[s]=i;
           }
        }
        return maxlen;// Your code here
    }
};

///for k
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int s=0,maxlen=0,count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
         
           s+= nums[i];
           if(s==k)
           count++;
           if(mp.find(s-k)!=mp.end()){
            count+=mp[s-k];
           }
           mp[s]++;
        }
        return count;// Your code here 
    }
};
