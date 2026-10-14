#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef tuple<int, int, bool> tiib;

int n, m, a, b, d, ret, here, cnt, dist[4001], dist_wolf[4001][2];

vector<pii> adj[4001];
const int INF = 987654321;

void dikstra() {
    fill(dist, dist + 4001, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[1] = 0;
    pq.push({0,1});
    while(pq.size()) {
        int here = pq.top().second;
        int here_dist = pq.top().first;
        pq.pop();
        if(dist[here] != here_dist) continue;
        for(pii there: adj[here]) {
            int nxt = there.second;
            int d = there.first;
            if(dist[nxt] > dist[here] + d) {
                dist[nxt] = dist[here] + d;
                pq.push({dist[nxt], nxt});
            }
        }
    }
}

void dikstra2() {
    fill(&dist_wolf[0][0], &dist_wolf[0][0] + 4001 * 2, INF);
    priority_queue<tiib, vector<tiib>, greater<tiib>> pq;
    dist_wolf[1][0] = 0;
    pq.push({0, 1, 0});
    while(pq.size()) {
        int d, here, cnt; tie(d, here, cnt) = pq.top();
        pq.pop();
        for(pii there: adj[here]) {
            int nxt = there.second;
            int d = !cnt ? there.first / 2 : there.first * 2;
            if(dist_wolf[nxt][!cnt] > dist_wolf[here][cnt] + d) {
                dist_wolf[nxt][!cnt] = dist_wolf[here][cnt] + d;
                pq.push({dist_wolf[nxt][!cnt], nxt, !cnt});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> d;
        adj[a].push_back({d * 2, b});
        adj[b].push_back({d*2, a});
    }
    dikstra();
    dikstra2();

    for(int i = 2; i <= n; i++) {
        int d = min(dist_wolf[i][0], dist_wolf[i][1]);
        if(d > dist[i]) ret++;
    }

    cout << ret << '\n';

    return 0;
}