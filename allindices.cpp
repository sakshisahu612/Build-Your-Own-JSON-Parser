#include<bits/stdc++.h>
using namespace std;

vector<int> allindices(int idx, vector<int>&arr, vector<int>&ans, int target){
	if(idx == arr.size()){
		return ans;
	}
	// ELEMENT FOUND
	if(arr[idx] == target){
		ans.push_back(idx) ;
	}
	// MOVE FORWARD
	return allindices(idx+1,arr,ans,target);

}
int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i<n; i++){
		cin >> arr[i];
	}
	vector<int> ans;
	allindices(0, arr, ans, 3);
	for(int x : ans){
		cout << x << endl;
	}
	return 0;
}