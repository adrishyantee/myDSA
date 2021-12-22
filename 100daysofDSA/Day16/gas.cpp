class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       int total_cost=0,total_fuel=0,n=cost.size();
        
        for(int i=0;i<n;i++){
            total_cost+=cost[i];
            total_fuel+=gas[i];
        }
        if(total_fuel<total_cost){
            return -1;
        } 
        
        int curr=0,start=0;
        for(int i=0;i<n;i++){
            if(curr<0){
                start=i;
                curr=0;
            }
                curr+= gas[i]-cost[i];
            
        }
        return start;
    }
};