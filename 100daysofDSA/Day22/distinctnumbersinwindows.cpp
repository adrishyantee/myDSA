vector<int> Solution::dNums(vector<int> &A, int B) {
    map<int,int> mp;


    vector<int> ans;
    if(B>A.size())
    return ans;
    for(int i=0;i<B;i++)
    mp[A[i]]++;
    ans.push_back(mp.size());

    for(int i=1;(i+B-1)<A.size();i++){
        mp[A[i-1]]--;
        mp[A[i+B-1]]++;
        if(mp[A[i-1]]==0)
        mp.erase(A[i-1]);
        ans.push_back(mp.size());

    }
    return ans;
}
