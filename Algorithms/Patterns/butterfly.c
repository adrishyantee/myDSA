#include <stdio.h>

int main(){

    int n; scanf("%d", &n);

    for(int i= 0; i< n/2 ;i++){
        for(int j=0;j<=i;j++)
        printf("* ");
        for(int s=0;s<n - 2*(i+1);s++)
        printf("  ");
        for(int k=0;k<=i;k++)
        printf("* ");

        printf("\n");
    }

    for(int i= n/2-1; i>=0 ;i--){
        for(int j=0;j<=i;j++)
        printf("* ");
        for(int s=0;s<n-2*(i+1);s++)
        printf("  ");
        for(int j=0;j<=i;j++)
        printf("* ");

        
        printf("\n");
    }
    return 0;
    
}