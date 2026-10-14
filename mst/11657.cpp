#include<bits/stdc++.h>
#define MX 510
#define INF 1e9
using namespace std;
using pii = pair<int,int>;
using ll = long long;

int N, M;
ll dist[MX];
vector<pair<pii, int>> adj;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=1l; i <= N; i++) dist[i] = INF;
    for(int i = 0; i< M; i++) {
        int a,b,c; cin >> a >> b >> c;
        adj.push_back({{a, b}, c});
    }

    dist[1] = 0;
    for(int i = 1; i< N ; i++) {
        for(const auto nex : adj) {
            if(dist[nex.first.first] == INF) continue;
            if (dist[nex.first.second] > dist[nex.first.first] + nex.second) {
                dist[nex.first.second] = dist[nex.first.first] + nex.second;
            }
        }
    }

    for(const auto i : adj) {
        if (dist[i.first.first] == INF) continue;
        if(dist[i.first.second] > dist[i.first.first] + i.second) {
            cout << -1;
            return 0;
        }
    }

    for(int i = 2; i <= N; i++) cout << ((dist[i] == INF) ? -1 : dist[i]) << '\n';

    return 0;
}