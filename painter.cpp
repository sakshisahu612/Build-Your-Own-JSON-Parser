#include<bits/stdc++.h>
using namespace std;
bool check(long long x, long long k, long long *arr, int n){
    long long remaining_time = x;
    long long painters_needed = 1;
    for(long long i = 0; i<n; i++){
        if(remaining_time >= arr[i]){
            remaining_time -= arr[i];
        }
        else{
            painters_needed += 1;
            remaining_time = x - arr[i];
        }
    }
    if(painters_needed > k){
        return false;
    }
    return true;
}
int main(){
    long long t;
    cin >> t;
    while(t--){
        long long n,k;
        cin >> n >> k;
        long long arr[n];
        long long maxx = LLONG_MIN;
        long long sum = 0;
        for(long long i = 0; i<n; i++){
            cin >> arr[i];
            maxx = max(maxx, arr[i]);
            sum += arr[i];
        }
        long long low = maxx;
        long long high = sum;
        long long ans = 0;
        while(low <= high){
            long long mid = (low+high)/2;
            if(check(mid,k,arr,n)){
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