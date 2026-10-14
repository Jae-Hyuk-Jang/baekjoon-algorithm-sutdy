#include<bits/stdc++.h>
#define INF 987654321
using namespace std;
using tu3 = tuple<int,int,int>;

int dist[101][10001];
int N, M, K;
vector<tu3> adj[101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test_case; cin >> test_case;
    for(int t = 0; t < test_case; t++) {
        cin >> N >> M >> K;
        for(int i=0; i<101; i++) adj[i].clear();
        
        for(int i = 0; i<= N; i++) {
            for(int j = 0; j<= M; j++) {
                dist[i][j] = INF;
            }
        }

        for(int k = 0; k< K; k++) {
            int u, v, c, d; cin >> u >> v >> c >> d;
            adj[u].push_back({v, c, d});
        }
        
        queue<pair<int, pair<int,int>>> pq; // time, node, cost
        pq.push({0, {1, 0}});
        dist[1][0] = 0;

        while(!pq.empty()) {
            int cur = pq.front().second.first;
            int time = pq.front().first;
            int cost = pq.front().second.second;

            //if(cur == N) break;
            //cout << cost << endl;
            pq.pop();

            if(dist[cur][cost] < time) continue;

            for(auto nex : adj[cur]) {
                int next, next_time, next_cost;
                tie(next, next_cost, next_time) = nex;
                next_time += time;
                next_cost += cost;
                //cout << next_cost << ' ' << next_time << '\n';
                //cout << dist[next][next_cost] << endl;
                if(next_cost <= M && next_time < dist[next][next_cost]) {
                    for(int j = next_cost + 1; j <= M; j++) {
                        if(dist[next][j] <= next_time) break;
                        dist[next][j] = next_time;
                    }
                    //cout << "here" << endl;
                    dist[next][next_cost] = next_time;
                    pq.push({next_time, {next, next_cost}});
                }
            }
        }

        int answer =INF;
        for(int i = 0; i<= M; i++) answer = min(answer, dist[N][i]);

        if(answer == INF) cout << "Poor KCM" << '\n';
        else cout << answer << '\n';
    }

    return 0;
}