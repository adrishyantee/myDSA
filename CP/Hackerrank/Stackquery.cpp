#include <bits/stdc++.h>

using namespace std;

vector<int> getMax(vector<string> operations) {
    stack<int>st;
    string option="";
    int max=0;
    vector<int> maximum;
    int arr[]={1,2,3};

    for (int i=0;i<operations.size();i++){
        int j=0;
        option = operations[i];
        if (option.find(' ') != string::npos){
        string s= option.substr(2);
        st.push(stoi(s));
        }
        else if(option=="2"){
            st.pop();
        }
        else{
            while (!st.empty()){
                if (st.top()>=max)
                max=st.top();
                st.pop();
            }
            maximum[j]=max;
            j++;
        }
}
return maximum;
}

int main()
{
    int n;
    cin>>n;

    vector<string> operations;
    vector<int> a;

    while (n--){
        string temp;
        getline(cin,temp,'\n');
        operations.push_back(temp);
    }

    a=getMax(operations);

    for(int i=0;i<a.size();i++)
    cout<<a[i]<<endl;

    return 0;
}
  