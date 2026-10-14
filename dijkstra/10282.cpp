#include<bits/stdc++.h>
#define MX 10001
#define INF 1e9
using namespace std;
using pii = pair<int,int>;

int T, N, D, C;
int dp[MX];

void dijkstra(vector<pii> adj[]) {
    dp[C] = 0;
    priority_queue<pii> pq;
    pq.push({ 0, C});
    
    while(!pq.empty()) {
        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if(dp[cur] < cost) continue;

        for(const auto& n : adj[cur]) {
            int ncost = cost + n.second;
            int next = n.first;
            if(ncost < dp[next]) {
                dp[next] = ncost;
                pq.push({-ncost, next});
            }
        }
    }

    int cnt = 0, ans = 0;
    for(int i=1; i<= N; i++) {
        if(dp[i] != INF) {
            cnt++;
            ans = max(ans, dp[i]);
        }
    }
    cout << cnt << ' ' << ans << '\n';
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--) {
        vector<pii> adj[MX];
        cin >>  N >> D >> C;
        int a, b, s;
        for(int i = 0; i < D; i++) {
            cin >> a >> b >> s;
            adj[b].push_back({a, s});
        }
        fill(dp, dp + MX , INF);
        dijkstra(adj);
    }

    return 0;
}