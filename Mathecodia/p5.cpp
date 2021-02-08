#include <stdio.h> 
int main() 
{ 
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++){
	    int n,j;
	    scanf("%d",&n);
	    char arr1[n],arr2[n];
	    scanf("%s", arr1); 
	    scanf("%s", arr2); 
	    int count = 0;
	   // int flag = 0;
	    for(int j=0;j<n;j++){
	        if(arr1[j]!=arr2[j]){
	            if(count==0){
	                count++;
	               // flag = arr2[j] - '0';
	            } else if(arr1[j]!=arr1[j-1]){
	                count++;
	            }
	        }
	    }
	    printf("%d\n",count);
	}
} 

