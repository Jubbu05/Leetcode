#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	vector<int> hash(n+1, 0);
	pair<int,int> ans;

	for(int i=0; i<n; i++){
		hash[arr[i]]++;
	}

	for(int i=1; i<n; i++){
		if(hash[i]==0){
			ans.first=i;
		}
		if(hash[i]==2){
			ans.second=i;
		}
	}
	return ans;
}
