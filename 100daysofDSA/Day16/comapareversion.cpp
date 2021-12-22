class Solution {
public:
    
    vector<int> findarray(string v){
        int i=0;
        int n=v.size();
        vector<int> ver;
        
        while(i<n){
        int num=0;
        while(i<n && v[i]!='.'){
            num = (num*10) + (int)(v[i]-'0');
            i++;
        }
            ver.push_back(num);
            i++;
        }
        return ver;  
    }
    int compareVersion(string version1, string version2) {
        vector<int> ver1= findarray(version1);
        vector<int> ver2= findarray(version2);
        
        int i=0,j=0;
        int n = ver1.size(), m = ver2.size();
        while(i<n && j<m){
            if(ver1[i]>ver2[j])
                return 1;
            else if(ver1[i]<ver2[j])
                return -1; 
                i++;
                j++;  
        }
        if(n==m)
            return 0;
        
        else if(n>m){
            while(i<n && ver1[i]==0){
                i++;
            }
            if(i<n && ver1[i]!=0)
                return 1;
        }
        else if(m>n){
             while(j<m && ver2[j]==0){
                j++;
            }
            if(j<m && ver2[j]!=0)
                return -1;  
        }
        return 0; 
    }
};