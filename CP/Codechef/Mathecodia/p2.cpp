#include<stdio.h>

long long calcgcd(long long n1, long long n2)
{
    if (n2 == 0)
        return n1; 
    return calcgcd(n2, n1%n2); 
}

int gcd(int a, int b) 
{ 
    if (a == 0)
        return b; 
    return gcd(b % a, a); 
} 
 
// Function to return LCM of two numbers 
int lcm(int a, int b) 
{ 
    return (a / calcgcd(a, b)) * b;
}

// long long combination(int n, int r)
// {
//     long long p = 1, k = 1;
//     if (n - r < r)
//         r = n - r;
//     if (r != 0) {
//         while (r) {
//             p *= n;
//             k *= r;
//             long long m = calcgcd(p, k);
//             p /= m;
//             k /= m;
//             n--;
//             r--;
//         }
//     }
//     else
//         p = 1;
//     return p;
// }

int checkSum(int a, int b, int n){
    long int multiple = lcm(a,b);
    if(multiple/a <= n/2 && multiple/b<= n/2){
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int t,i;
    scanf("%d",&t);
    double ans[] = {0.000000,0.333333,0.466667,0.428571,0.511111,0.484848,0.494505,0.516667,0.516340,0.494737};
    for(i=0;i<t;i++){
        int n,j,k;
        scanf("%d",&n);
        if(n<=20){
            int index= (n/2)-1;
            printf("%f\n",ans[index]);
            continue;
        }
        // long long totalWays = combination(n,2);
        double count = 0;
        double sampleSpace = 0;
        for(j=1;j<n;j++){
            for(k=j+1;k<=n;k++){
                count+=checkSum(j,k,n);
                sampleSpace++;
            }
        }
        double prob = (count/sampleSpace);
        printf("%f\n",prob);
    }
}
