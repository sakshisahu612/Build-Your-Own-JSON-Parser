#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long target;
        cin >> target;
        vector<int> arr(n);
        for(int i = 0; i<n; i++){
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        long long bestsum = arr[0]+arr[1]+arr[2];
        for(int j = 1; j<n; j++){
            int i = 0;
            int k = n-1;
            long long sum = arr[i]+arr[j]+arr[k];
            while(i < j && j < k){
                if(abs(sum-target) < abs(bestsum-target)){
                    bestsum = sum;
                }
                if(sum > target){
                    k--;
                }
                else{
                    i++;
                }
            }
        }
        cout << abs(bestsum-target) << endl;
    }
    return 0;
}