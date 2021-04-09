#include <bits/stdc++.h>

using namespace std;

// Complete the minimumNumber function below.
int minimumNumber(string s) {
    int n=s.length();
int c=0,count=0,d=0,lc=0,uc=0,sp=0;
    if(n<=6)
    c=6-n;
    
for(int i =0;i<n;i++){
    if(s[i]>='0' && s[i]<='9')
    d++;
    if(s[i]>='a' && s[i]<='z')
    lc++;
    if(s[i]>='A'&& s[i]<='Z')
    uc++;
    if(s[i]>='!' && s[i]<='/')
    sp++;  
}
if(d==0)
count++;
if(lc==0)
count++;
if(uc==0)
count++;
if(sp==0)
count++;
cout<<d<<lc<<uc<<sp<<endl;
cout<<count<<endl;

if(c>=count)
return c;
else if(count>c)
return count;
else
return 0;
}

int main()
{
    string password;
    getline(cin, password);

    int answer = minimumNumber(password);

    cout << answer << "\n";

    return 0;
}

//7
//AUzs-nV