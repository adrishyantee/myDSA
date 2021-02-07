#include<stdio.h>
#include<math.h>

//double roundNo(double num) 
//{ 
//    return ((num - floor(num)) < 0.5) ? num - 0.5 : num + 0.5; 
//} 

int main() {
    int t;
    scanf("%d",&t);
//    double multiplier1 = 2*sqrt(2)+3;
//    double multiplier2 = (double)1.0/multiplier1;
    for(int i=0;i<t;i++){
        int n;
        scanf("%d",&n);
//        long long int sum = (2 + multiplier1*multiplier1 + multiplier2*multiplier2)*n*n;
    long long int sum = (long long int)36 * n *n; 
        printf("%lld\n",sum);
    }
    return 0;
}
