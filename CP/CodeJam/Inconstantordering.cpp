#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
    int n;
    cin>>n;
    int val,sum=0;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    string temp="";
    string temp1="";
    string temp2="";
    for(int i=n-1;i>=0;i--){
        char A='A';
        char B ='B';
        if(i%2!=0){
        for(int j=0;j<arr[i];j++){

            temp1=A+temp1;
            A=(char)A+1;
        }
        temp=temp1+temp;
        }
        else{
            for(int j=0;j<arr[i];j++){
            temp2+=B;
            B=(char)B+1;
            }
            temp=temp2+temp;
        }
    }
for(int k=0;k<temp.length();k++){
    if(temp[k]==temp[k+1])
    temp[k]=(char)(temp[k]+1);
}
    temp="A"+temp;
    cout<<"Case #"<<t<<": "<<temp<<endl;
    }
    return 0;
}