#include<bits/stdc++.h>
using namespace std;

int firstindex(int idx, vector<int>&arr, int target){
	if(idx == arr.size()){
		return -1;
		// element does not exist in the arr
	}
	if(arr[idx] == target){
		return idx;
	}
	else{
		int index = firstindex(idx+1, arr, target);
		return index;
	}
}
int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i<n; i++){
		cin >> arr[i];
	}
	int ans = firstindex(0, arr, 8);
	cout << "First index of 8 is : " << ans;
	return 0;
}