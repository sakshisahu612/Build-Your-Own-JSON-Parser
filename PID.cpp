#include<bits/stdc++.h>
using namespace std;
void PID(int n){
	if(n == 0){
		return;
	}
	cout << n << endl;
	PID(n-1);
	cout << n << endl;
}

int main(){
	int n;
	cin >> n;
	PID(n);
	return 0;
}