#include<bits/stdc++.h>
#define MX 50001
#define INF 1e9
using namespace std;
using pii = pair<int,int>;

int n, m;
int dist[MX];
vector<pii> v[MX];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while(m--) {
        int a, b, c; cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    fill(dist, dist + n + 1, INF);
    priority_queue<pii> pq;
    pq.push({0, 1});
    dist[1] = 0;

    while(!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for(const auto& n : v[cur]) {
            if(dist[n.first] > n.second + cost) {
                dist[n.first] = n.second + cost;
                pq.push({ -dist[n.first], n.first});
            }
        }
    }

    cout << dist[n];
}