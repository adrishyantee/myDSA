#include <bits/stdc++.h>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;
        for (int i = 1; i <= n; i++) {
            if (i < n) {
                for (int j = n - i; j > 0; j--) {
                    cout<<" ";
                    
                }
            }
            cout<<"*";
            // print stars:
            if (i != 1) {
                for (int j = 1; j <= 2 * i - 3; j++) {
                    cout<<" ";
                }
                cout<<"*";
            }
            for (int j = n - i; j > 0; j--) {
               cout<<" ";
            }
            for (int k = 2; k <= m; k++) {
            for (int j = n - i - 1; j > 0; j--) {
                cout<<" ";
                // }
            }
            if (i < n) {
                cout<<"*";
            }
            // print stars:
            if (i != 1) {
                for (int j = 1; j <= 2 * i - 3; j++) {
                    cout<<" ";
                }
                cout<<"*";
            }
            for (int j = n - i ; j > 0; j--) {
                cout<<" ";
            }
        }
        cout<<endl;
        }
    return 0;
}