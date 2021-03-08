#include<stdio.h>
#include<math.h>
double roundNo(double num) 
{ 
double s;
    if ( (num - (floor(num) + ceil(num))/2) < 0.5 )
	s= floor(num); 
	else
	s= ceil(num); 
	return s;
} 

int main() {
    int t;
    scanf("%d",&t);
   double multiplier1 = 2*sqrt(2)+3;
   double multiplier2 = 1/multiplier1;
    for(int i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        double sum =(double) (2 + multiplier1*multiplier1 + multiplier2*multiplier2)*n*n;
        int m = roundNo(sum);
        printf("%d\n",m);
    }
    return 0;
}
