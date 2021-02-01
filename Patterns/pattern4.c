#include <stdio.h>
int main()
{
    int i,j;
    for (i=3;i>=1;i--)
    {
        for(j=i+1;j>=3-i;j--)
        {
            printf("%d",j);
        }
        printf("\n");
    }
return 0;
}