class Solution {
public:
    double myPow(double x, int y) {
    double ans =1.0;
    long y1=y;
    if(y<0) y1=-1*y1;
    while(y1>0){
        if(y1%2==0){
            x*=x;
            y1/=2;
        }
         else{
             ans*=x;
             y1-=1;
         }      
    }
            if(y>0)  return ans;
                else return 1/ans;   
    }
};