#include <stdio.h>
int main()
{
    int i,j,k,l;
    for (i=1;i<=4;i++)
    {
        for (k=3;k>=i;k--)
        {
            printf(" ");
        }
        for(j=1;j<=i;j++)
        {
            printf("%d",j);
        }
        for (l=i-1;l>0;l--)
        {
            printf("%d",l);
        }
        printf("\n");
    }
return 0;
}