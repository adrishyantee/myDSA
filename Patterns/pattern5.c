#include <stdio.h>
int main() {
   int rows=7, coef = 1, space, i, j;;
   for (i = 0; i < rows; i++) {
      for (space = 1; space <= rows - i; space++)
         printf("  ");
      for (j = 0; j <= i; j++) {
         if (j == 0 || i == 0 || j==i)
            coef = 1;
         else if (j<(i/2))
            coef =  (j + 1) ;
        else if (j==(i/2))
            coef = j+1;
        else
           coef = (i - j + 1);
         printf("%4d", coef);
      }
      printf("\n");
   }
   return 0;
}