#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n,k;
        cin >> n >> k;
        long long arr[n];
        for(long long i = 0; i<n; i++){
            cin >> arr[i];
        }
        map<long long, long long> mapp;
        long long head = -1;
        long long tail = 0;
        long long distinct = 0;
        long long ans = 0;

        while(tail < n){
            // insert arr[head] into ds
            while(head+1 < n && (distinct < k || mapp[arr[head+1]] != 0)){
                head++;
                if(mapp[arr[head]] == 0){
                    distinct++;
                }
                mapp[arr[head]]++;
            }
            // update ans
            ans += (head-tail+1);
            //0 elements in ds

            mapp[arr[tail]]--;
            if(mapp[arr[tail]] == 0){
                distinct--;
            }
            tail++;
            
        }

        cout << ans << endl;
    }
    return 0;
}