int findPlatform(int arr[], int dep[], int n)
    {
    sort(arr,arr+n);
    sort(dep,dep+n);
    int count=0,mini=0;
    int i=0,j=0;
    while(i<n && j<n){
        if(arr[i]<=dep[j]){
           count++;
           i++;
           mini=max(count,mini); 
        }
        else{
            count--;
            j++;
        }
    }
    return mini;
    }
};
