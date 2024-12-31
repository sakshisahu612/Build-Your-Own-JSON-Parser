#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int main(){
	int n;
	cin >> n;
	int dp[n+1][n+1];
	int grid[n+1][n+1];
	for(int i = 1; i<=n; i++)
		for(int j = 1; j<=n; j++){
			char c;
			cin >> c;
			if(c == '.'){
				grid[i][j] = 0;
			}
			else{
				grid[i][j] = 1;
			}
		}

	for(int i = n; i >= 1; i--){
		for(int j = n; j>=1; j--){
			if(grid[i][j] == 1){
				dp[i][j] = 0;
				continue;
			}
			if(i == n && j == n){
				dp[i][j] = 1;
			}
			else{
				int op1 = (i == n) ? 0 : dp[i+1][j];
				int op2 = (j == n) ? 0 : dp[i][j+1];
				dp[i][j] = (op1 + op2) % mod;
				//(grid[i][j] == 1){
				//p[i][j] = 0;
				
			}
		}
	}
	if(grid[n][n] == 1){
		cout << 0 << endl;
	}
	else{
		cout << dp[1][1] << endl;
	}
	return 0;
}