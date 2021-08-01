#include <stdio.h>

int main(){

    int n; scanf("%d", &n);

    for(int i = 0; i < n ;i++){
        for(int j = n-1; j > i ;j--)
        printf(" ");
        for(int k= i+1 ;k >= 1;k--)
        printf("%d",k);
        for(int m = 2; m <=i+1;m++)
            printf("%d",m);

        printf("\n");
    }

    return 0;
}