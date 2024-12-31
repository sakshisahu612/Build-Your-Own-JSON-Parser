#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,x;
	cin >> n >> x;
	int book[n+1];
	int price[n+1];
	for(int i = 1; i<=n; i++){
		cin >> book[i];
	}
	for(int i = 1; i<=n; i++){
		cin >> price[i];
	}
	int dp[n+1][x+1];
	for(int i = 0; i<=n; i++){
		for(int money = 0; money<=x; money++){
			if(i == 0 || money == 0){
				dp[i][money] = 0;
			}
			else{
				int op1 = (i == 0) ? 0 : dp[i-1][money];
				int op2 = book[i] + dp[i-1][money-price[i]];
				
							}
		}
	}
}