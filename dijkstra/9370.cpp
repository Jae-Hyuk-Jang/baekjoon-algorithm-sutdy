#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

const int INF = 987654322;
int T, dist[2004], n, m, t, s, g, h, a, b, d;
int candi[101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--) {
        vector<pii> adj[2004];

        cin >> n >> m >> t;
        cin >> s >> g >> h;

        for (int i = 0; i < m; i++) {
            cin >> a >> b >> d;
            d *= 2;
            if ((a == g && b == h) || (a == h && b == g)) d--;

            adj[a].push_back({d, b});
            adj[b].push_back({d, a});
        }

        for (int i = 0; i < t; i++) cin >> candi[i];
        sort(candi, candi + t);

        fill(dist, dist + 2004, INF);

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, s});
        dist[s] = 0;

        while(!pq.empty()) {
            int here_dist = pq.top().first;
            int here = pq.top().second;
            pq.pop();

            if (dist[here] != here_dist) continue;

            for (pii nxt : adj[here]) {
                int there_dist = nxt.first;
                int there = nxt.second;

                if (dist[there] > dist[here] + there_dist) {
                    dist[there] = dist[here] + there_dist;
                    pq.push({dist[there], there});
                }
            }
        }

        for (int i = 0; i < t; i++) {
            if (dist[candi[i]] % 2 == 1) {
                cout << candi[i] << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}