 #include <bits/stdc++.h>
 using namespace std;
 
    int reverse(int x) {
        int rev=0;
        while(x){
             if(rev>INT_MAX/10 || rev<INT_MIN/10)
                return 0;
            else{
            int d=x%10;
            x/=10;
            rev=rev*10+d;
            cout<<rev<< " ";
            }
        }
        return rev;   
    }

    int main(){

        int m=-321;
        cout<<reverse(m);
        return 0;
    }