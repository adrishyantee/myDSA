#include <bits/stdc++.h>

using namespace std;

// Complete the encryption function below.
string encryption(string s) {
    vector<vector<char>>st;
    string temp="";
    
    for(int i=0;i<s.length();i++){
        if(s[i]!=' ')
            temp+=s[i];
    }
    
    int rows=0,columns=0;
    int len=temp.length();
    double sq=sqrt(len);
    if((sq-(int)sq)==0){
    rows=sq;
    columns=sq;
    }
    else{
        rows=(int)sq;
        columns=(int)sq+1;
        if(rows*columns<len)
        rows++;
    }
    
    int k=0;
    for(int i=0;i<rows;i++){
        vector<char>stt={};
        for(int j=0;j<columns;j++){
            stt.push_back(temp[k]);
            k++;
        }
        st.push_back(stt);
    }
    
    string temp2;
    int m,n;
    for(m=0;m<columns;m++){
        for( n=0;n<rows;n++){
        temp2+=st[n][m];
        }
        if(m!=columns-1&& n!=rows-1)
        temp2+=' ';
    }
    return temp2;
}

int main()
{
    string s;
    getline(cin, s);

    string result = encryption(s);

    cout<<result << "\n";
    return 0;
}
