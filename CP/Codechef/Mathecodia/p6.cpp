#include <bits/stdc++.h> 
using namespace std; 

int main(){
int T;
cin>>T;

for(int test = 0; test< T;test++){
	
	long long int N;
	cin>>N;
	long long int MIN=N+6;
	long long int MAX=N+6;
	long long int sum=0;
	for(long long int x=0;x<=N+6;x++){
	for(long long int y=0;x<=N+6;y++){
	for(long long int z=0;x<=N+6;z++){
		sum = x+y+z;
		if (sum == (N+6)){
		if(sum < MIN)
		MIN = sum;
		if(sum > MAX)
		MAX = sum;	
	}
	else
	continue;
	}
	}
	}
	cout<<MIN<<MAX<<endl;	
	}
return 0;
}
