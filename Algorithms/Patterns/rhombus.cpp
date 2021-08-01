#include <stdio.h>

int main(){

    int n; scanf("%d", &n);
    int m; scanf("%d", &m);

    for(int i= 0; i< n ;i++){
        for(int j=n;j>i;j--)
        printf(" ");
        for(int k=0;k<m;k++)
        printf("* ");

        printf("\n");
    }

    return 0;
}