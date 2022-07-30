    static bool comparator(Job a, Job b){
        if(a.profit>b.profit)
        return true;
        else
        return false;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        int maxi=-1;
        sort(arr,arr+n,comparator);
       for(int i=0;i<n;i++) {
           maxi=max(arr[i].dead,maxi);
       }
      vector<int> avail(maxi,0);
      int profit = 0;
       for(int i=0;i<n;i++){
           int j=arr[i].dead-1;
           while(j>=0){
           if(avail[j]==0){
           avail[j]=1;
           profit+=arr[i].profit;
           break;
           }
           else
           j--;
           }
       }
       int count=0;
       for(int i=0;i<maxi;i++){
           if(avail[i]==1)
           count++;
       }
       return {count,profit};
       
    } 
    };