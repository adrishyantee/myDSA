#include <stdio.h>

int main(){

    int n; scanf("%d", &n);

    for(int i = 0; i < n ;i++){
        for(int j = n-1; j>i ;j--)
        printf(" ");
        for(int k= 1;k <= i+1;k++)
        printf("%d ",k);

        printf("\n");
    }

    return 0;
}