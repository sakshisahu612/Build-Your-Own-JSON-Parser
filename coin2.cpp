#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int main(){
	int n, x;
	cin >> n >> x;
	vector<int> c(n+1);
	for(int i = 1; i<=n; i++){
		cin >> c[i];
	}

	int dp[n+1][x+1];
	for(int i = 1; i<=n; i++){
		for(int sum = 0; sum <= x; sum++){
			if(sum == 0){
				dp[i][sum] = 1;
			}
			else{
				int op1 = (i == 1) ? 0 : dp[i-1][sum];
				int op2 = (sum < c[i]) ? 0 : dp[i][sum-c[i]];
				dp[i][sum] = (op1 + op2)%mod;			
			}
		}
	}
	cout << dp[n][x];
	return 0;
}	