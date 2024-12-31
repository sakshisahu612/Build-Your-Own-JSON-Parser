#include<bits/stdc++.h>
using namespace std;
void display_array(vector<int>arr, int idx){
	if(idx == arr.size()){
		return;
	}
	cout << arr[idx] << " ";
	display_array(arr, idx+1);
}
int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i<n; i++){
		cin >> arr[i];
	}
	display_array(arr,0);
	return 0;
}