class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int rev =0;
        int j=0;
        for(int i=31;i >=0;i--){
            int mask = (1<<i);
             if((n & mask)!=0)
             {
               int smask = (1<<j);
                rev|=smask;
           
             }
                  j++;
        }
        return rev;
    }
};