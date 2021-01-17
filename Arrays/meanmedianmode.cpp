#include <bits/stdc++.h> 

using namespace std;

int main() {

    int n,i;
    double value,sum=0.0,median=0.0;
    cin>>n;
    vector <double> arr{};
    for(i=0;i<n;i++)
    {
    cin>>value;
    arr.push_back(value);
    }
    for(double s:arr)
    {
    sum=sum+s;
    }
    double mean =sum/n;
    
    cout<<fixed<<setprecision(1);
    cout<<mean<<endl;
    



     int j;
     double temp=0.0;
    for (i = 0; i < n-1; i++)      
    for (j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
        {
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    if(n%2==0)
    {
        int k=arr[n/2-1];
        int l=arr[(n/2)+1-1];
        median = (k+l)/2.0;
    }
    else
    {
     median = arr[(n+1)/2-1];
    }
    cout<<fixed<<setprecision(1);
    cout<<median<<endl;

    int mode;
    int count,max=0;
        for(int i=0;i<n;i++)
       {
            temp=arr[i];
            count=0;
            for(int j=0; j<n; j++)
            {
                if(temp==arr[j])
                {
                    count++;
                }
                if(count>max)
                {
                    max=count;
                    if(max==1)
                    {
                        mode=arr[0];
                    }
                    mode=temp;
                }
            }           
        }
    cout<< mode<<endl; 
    
    //* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;

}
