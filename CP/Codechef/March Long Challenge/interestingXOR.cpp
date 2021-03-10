#include <bits/stdc++.h>
using namespace std;

 //BRUTE FORCE SOLUTION
void XOR(){
    
    long int T;
    cin>>T;

    while(T--){
        long int C;
        cin>>C;
        long int d=0,A,B;

        while(d>=0){
            if(pow(2,d)>C)
            break;
            else d++;
        }
        long int MAX=0;
        for (long int A=0;A<pow(2,d);A++){
               int B=C^A;
               if(B<pow(2,d) && (A*B)>MAX)
               MAX=A*B;
           }
        cout<<MAX<<endl;
    }
}

//OPTIMISED SOLUTION
int main(){
    long int T;
    cin>>T;

    while(T--){
        long int C;
        cin>>C;
        long int d=0,A,B;

        while(d>=0){
            if(pow(2,d)>C)
            break;
            else d++;
        }

        long int MAX=0;
        A= pow(2,d-1)-1;//this line removes the loop the maximum will happen at this number only
        B=C^A;
        if(B<pow(2,d) && (A*B)>MAX)
        MAX=A*B;
        cout<<MAX<<endl;
    }
    return 0;
}