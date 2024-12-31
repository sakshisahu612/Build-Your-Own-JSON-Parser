#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i<n; i++){
		cin >> arr[i];
	}

	int ans = -1;
	int low = 0, high = n-1;
	while(low <= high){
		int mid = (low+high)>>1;
		if(arr[mid] == 0){
			low = mid+1;
		}
		else{
			ans = mid;
			high = mid-1;
		}
	}
	cout << "First one is at index: " << ans << endl;
	return 0;

}