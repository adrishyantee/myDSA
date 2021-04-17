#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
    string s;
    cin>>s;
    string temp1=s;
    string temp2=s;
    int I=1,O=1;

while(O!=0 && I!=0){ 
    if(I!=0){
        if(s[0]=='I'&& s[s.length()-1]=='I'){
           temp1.erase(temp1.begin()+0);
           temp2.erase(temp2.begin()+s.length()-1);
           if(temp1[0]=='I'&& temp1[temp1.length()-1=='I']){
           s.erase(s.begin()+0);
           temp1=s;
           temp2=s;
           O=0;
           break;
           }

           else if(temp2[0]=='I'&& temp2[temp2.length()-1=='I']){
           s.erase(s.begin()+s.length()-1);
           temp1=s;
           temp2=s;
           O=0;
           break;
           }
           
           else{
               if(s[0]=='I'){
               s.erase(s.begin()+0);
               temp1=s;
               temp2=s;
               continue;
               }
               else{
                   s.erase(s.begin()+s.length()-1);
                   temp1=s;
                   temp2=s;
                   continue;
               }

           }
        }
        else{
            I=0;
            break;
        }
        if(s=="")
        O=0;
        break;
    }
            
   if(O!=0){
        if(s[0]=='O'&& s[s.length()-1]=='O'){
           temp1.erase(temp1.begin()+0);
           temp2.erase(temp2.begin()+s.length()-1);
           if(temp1[0]=='O'&& temp1[temp1.length()-1=='O']){
           s.erase(s.begin()+0);
           temp1=s;
           temp2=s;
           I=0;
           break;
           }

           else if(temp2[0]=='O'&& temp2[temp2.length()-1=='O']){
           s.erase(s.begin()+s.length()-1);
           temp1=s;
           temp2=s;
           I=0;
           break;
           }
           
           else{
               if(s[0]=='O'){
               s.erase(s.begin()+0);
               temp1=s;
               temp2=s;
               continue;
               }
               else{
                   s.erase(s.begin()+s.length()-1);
                   temp1=s;
                   temp2=s;
                   continue;
               }

           }
        }
        else{
            O=0;
            break;
        }
        if(s=="")
        I=0;
        break;
        
   }


temp1=s;
temp2=s;
}
    if(O==0)
    cout<<"Case #"<<": I "<<1+s.length()<<endl;
    if(I==0)
    cout<<"Case #"<<": O "<<1+s.length()<<endl;
    }
    return 0;
}