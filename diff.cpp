#include<bits/stdc++.h>
using namespace std;
bool check(long long x, long long k, vector<long long>&arr){
    long long needed_points = 0;
    for(int i = 1; i<arr.size(); i++){
        needed_points += ((((arr[i]-arr[i-1])+x-1)/x))-1;
    }
    if(needed_points > k) return 0;
    return 1;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n,k;
        cin >> n >> k;
        vector<long long> arr(n);
        long long maxx = LLONG_MIN;

        for(int i = 0; i<n; i++){
            cin >> arr[i];
            maxx = max(maxx, arr[i]);
        }

        long long low = 1, high = maxx, ans = -1;
        while(low <= high){
            long long mid = (low + high)/2;

            if(check(mid,k,arr)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}