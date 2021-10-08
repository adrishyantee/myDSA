#include <bits/stdc++.h>
 using namespace std;

void printKMax(int arr[], int n, int k)
{

    deque<int> dq;
	vector<int> ans;
	int i=0,j=0;

	while(j<n){
		while (dq.size()>0 && dq.back()<arr[j]){
		dq.pop_back();
		}

		dq.push_back(arr[j]);

		if(j-i+1<k){  
		j++;
		}

		if(j-i+1==k){
		ans.push_back(dq.front());
		if(dq.front()==arr[i])
		dq.pop_front();
		i++;
		j++;
	    }
	}

for(int i=0;i<ans.size();i++){
	cout<<ans[i]<<" ";
}
cout<<endl;
}

int main()
{
	int arr[] = {1,3,-1,-3,5,3,6,7};
	int n=8;
	int k = 3;
	printKMax(arr, n, k);
	return 0;
}


 /*NAIVE APPROACH*/

    // multiset<int, greater<int>>s;
    // vector<int> ans;

    // for(int i=0;i<k;i++){
    //     s.insert(a[i]);
    // }

    // ans.push_back(*s.begin());

    // for(int i=k;i<n;i++){
    //     s.erase(s.lower_bound(a[i-k]));
    //     ans.push_back(*s.begin());
    // }

    // for(auto i:ans)
    // cout<<i<<" ";

