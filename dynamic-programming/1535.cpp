#include<iostream>
#include<algorithm>
#define MX 101
using namespace std;

int n, dp[MX], cost[MX], happy[MX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> cost[i];
    for (int i = 0; i < n; i++) cin >> happy[i];

    for (int i =0; i< n; i++) {
        for (int j = 100; j > cost[i]; j--) {
            dp[j] = max(dp[j], dp[j- cost[i]] + happy[i]);
        }
    }
    cout << dp[100];
    return 0;
}