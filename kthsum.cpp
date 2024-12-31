#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m,k;
vector<ll> arr,brr;

bool check(int mid){
    ll cnt = 0;
    for(int i = 0; i<n; i++){
        cnt += upper_bound(brr.begin(), brr.end(), mid-arr[i]) - brr.begin();
    }
    return cnt >= k;
}

void solve(){
    cin >> n >> m >> k;
        arr.resize(n);
        brr.resize(m);
        for(int i = 0; i<n; i++){
            cin >> arr[i];
        }
        for(int i = 0; i<m; i++){
            cin >> brr[i];
        }
        if(n > m){
            swap(n,m);
            swap(arr, brr);
        }
        ll low = arr[0]+brr[0];
        ll high = arr.back()+brr.back();
        ll ans = 0;
        while(low <= high){
            ll mid = (low+high)/2;
            if(check(mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        cout << ans << endl;
}


int main(){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}