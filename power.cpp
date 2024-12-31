#include<bits/stdc++.h>
using namespace std;
int pow(int x, int n){
	if(n == 0){
		return 1;
	}
	int pxn1 = pow(x,n-1);
	int pow = x * pxn1;
	return pow;
}


int main(){
	int x, n;
	cin >> x >> n;
	cout << pow(x,n);
	return 0;
}