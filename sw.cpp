#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<int> freq(100001, 0);
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            freq[arr[i]]++;
        }
        
        int k = 0;
        for (int i = 0; i < 100001; i++) {
            k += (freq[i] > 0);
            freq[i] = 0;
        }

        int head = -1, tail = 0;
        int distinct = 0;
        int ans = n;
        while (tail < n) {
            while (head + 1 < n && (distinct < k || (distinct == k && freq[arr[head + 1]] > 0))) {
                head++;
                if (freq[arr[head]] == 0) {
                    distinct++;
                }
                freq[arr[head]]++;
            }
            if (distinct == k) {
                ans = min(ans, head - tail + 1);
            }
            if (tail <= head) {
                freq[arr[tail]]--;
                if (freq[arr[tail]] == 0) {
                    distinct--;
                }
                tail++;
            } else {
                tail++;
                head = tail - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
