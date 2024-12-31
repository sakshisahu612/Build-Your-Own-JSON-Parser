#include<bits/stdc++.h>
using namespace std;
long long sum(long long x) {
    long long sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, s;
        cin >> n >> s;
        long long low = 1, high = n, ans = 0;
        while(low <= high){
            long long mid = low + (high-low)/2;
            if(mid - sum(mid) >= s){
                //ans = mid;
                high = mid-1;               
            }
            else{
                ans = mid;
                low = mid+1;

            }
        }
        cout << n-ans << endl;
    }
    return 0;
}