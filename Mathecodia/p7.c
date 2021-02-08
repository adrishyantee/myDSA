#include <stdio.h>

int main()
{
	int test,t;
	scanf("%d",&test);
	for(t=0;t<test;t++){
		int n,i,j;
		scanf("%d",&n);
		int len=n*n;
		int arr[len];
		for(i=0;i<len;i++)
		{
		scanf("%d",&arr[i]);
		}
		int count =0;
		for(i=0;i<len-1;i++)
		{
			if(i<len-n){
				int rem = arr[i]%2;
				if(arr[i+1]%2 == rem){
					count++;
					arr[i+1]=arr[i+1]+1;
				}
				if(arr[i+n]%2 == rem){
					count++;
					arr[i+n]=arr[i+n]+ 1;
				}
				}
				else{
					int rem = arr[i]%2;
					if (arr[i+1]%2 == rem){
					count++;
					arr[i+1] = arr[i+1]+1;
					}
		    	}
		    }
		printf("%d\n",count);
		for(i=0;i<len;i++)
		{
		    printf("%d ",arr[i]);
		    if((i+1)%n == 0){
		        printf("\n");
		    }
		}
	}
	return 0;
}
