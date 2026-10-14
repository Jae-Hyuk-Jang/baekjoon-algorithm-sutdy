#include<bits/stdc++.h>
#define MX 200002
#define INF 1e9
using namespace std;
typedef pair<int, int> pii;

int N, M;      
int st, en;
int a, b, c;

vector<pii> adj[MX];
int pre[MX];
int dist[MX];
bool forbid[MX];
priority_queue<pii, vector<pii>, greater<pii>> pq;


void dijkstra(int start) {
	fill(dist, dist + N + 1, INF);
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {
		int cur = pq.top().second;
		int co = pq.top().first;
		pq.pop();

		for (const auto& a : adj[cur]) {
			int nxt = a.first;
			int dco = a.second;

			dco += co;
			if (dco <= dist[nxt] && !forbid[nxt]) {
				if (dco < dist[nxt]) {
					dist[nxt] = dco;
					pre[nxt] = cur;
					pq.push({ dco, nxt });
				}
				else if (pre[nxt] > cur) {
					pre[nxt] = cur;
				}
			}
		 }
	}
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}
	cin >> st >> en; 
	
	int ans = 0;

	dijkstra(en);
	ans += dist[st];

	int idx = st;
	while (pre[idx] != en) {
		forbid[pre[idx]] = 1;
		idx = pre[idx];
	}


	dijkstra(st);
	ans += dist[en];
	
	cout << ans;

	return 0;
}