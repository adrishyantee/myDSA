class Solution {
public:
    int climbStairs(int n) {
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        int pp = 1,p=2;
        int res=0;
        for(int i=3;i<=n;i++){
            res=pp+p;
            pp=p;
            p=res;
        }
        
        return res;
       // if(n==0) 
       //     return 1;
       //  if(n<0)
       //      return 0;
       //  else
       //  return climbStairs(n-1)+climbStairs(n-2);
    }
};