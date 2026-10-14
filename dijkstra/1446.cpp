#include<bits/stdc++.h>
#define INF 1e9
#define MX 10001
using namespace std;
using pii = pair<int,int>;

int dp[MX];
vector<pii> arr[MX];
int n, d; 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> d;

    for(int i = 0; i < n; i++) {
        int s, e, price; cin >> s >> e >> price;
        arr[e].push_back({s, price});
    }
    fill(dp, dp + d + 1, INF);
    dp[0] = 0;

    for(int i = 1; i <= d; i++) {
        if(!arr[i].size()) dp[i] = dp[i-1] + 1;
        else {
            for(const auto& v : arr[i]) {
                dp[i] = min({dp[i], dp[i-1]+1, dp[v.first]+ v.second});
            }
        }
    }
    cout << dp[d];

    return 0;
}