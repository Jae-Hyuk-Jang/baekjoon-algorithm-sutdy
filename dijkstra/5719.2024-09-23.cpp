#include <bits/stdc++.h>
#define MX 501
using namespace std;

int N, M, S, D;
vector<pair<int, int>> adj[MX];
vector<int> pre[MX];
bool visited[MX];
int dist[MX];
priority_queue<pair<int, int>> pq;


void setup() {
    for (int i = 0; i < N; i++) {
        adj[i].clear();
        pre[i].clear();
        visited[i] = 0;
    }
}

void dijkstra() {
    fill(dist, dist + N, 1e9);
    

    dist[S] = 0;
    pq.push({ 0, S });

    while (!pq.empty()) {
        int acc = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (acc < dist[cur])continue;

        for (auto edge : adj[cur]) {
            int cost = edge.first;
            int next = edge.second;

            if (cost == -1) continue;

            if (dist[cur] + cost < dist[next]) {
                dist[next] = dist[cur] + cost;
                pre[next].clear();
                pre[next].push_back(cur);
                pq.push({ -dist[next], next });
            }
            else if (dist[cur] + cost == dist[next]) {
                pre[next].push_back(cur);
            }
        }
    }
  
}

void route(int cur) {
    if (visited[cur]) return;
    visited[cur] = true;
    for (auto prev : pre[cur]) {
        for (auto& n : adj[prev]) { // & 참조로 접근해야 한다. (값 변경위해) 
            if (n.second == cur) {
                n.first = -1;
                route(prev);
            }
        }
    }
}




int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        cin >> N >> M;
        if (N == 0 && M == 0) break;
        cin >> S >> D;

        for (int i = 0; i < M; i++) {
            int u, v, p;
            cin >> u >> v >> p;
            adj[u].push_back({ p, v });
        }
        
        dijkstra();
        route(D);
        dijkstra();

        cout << ((dist[D] == 1e9) ? -1 : dist[D]) << '\n';
        setup();
    }

    return 0;
}