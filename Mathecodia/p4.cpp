#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin>>t;
    double multiplier1 = 2.0*sqrt(2)+3.0;
    double multiplier2 = 1.0/multiplier1;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        double sum =(2.0 + multiplier1*multiplier1 + multiplier2*multiplier2)*n*n;
       cout<<ceil(sum)<<endl;
    }
    return 0;
}
