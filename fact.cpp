#include<bits/stdc++.h>
using namespace std;
int fact(int n){
	if(n == 0){
		return 1;
	}
	int fn1 = fact(n-1);
	int fn = n * fn1;
	return fn;
}
int main(){
	int n;
	cin >> n;
	int ans = fact(n);
	cout << ans;
	return 0;
}