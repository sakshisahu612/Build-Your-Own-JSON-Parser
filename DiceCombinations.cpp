#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int main(){
	long long n;
	cin >> n;
	vector<long long> dp(n+1, 0);
	dp[0] = 1;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j <= 6; j++){
			if(j > i){
				break;
			}
			dp[i] = (dp[i] + dp[i-j])%mod;
		}
	}
	cout << dp[n] << endl;
	return 0;
}