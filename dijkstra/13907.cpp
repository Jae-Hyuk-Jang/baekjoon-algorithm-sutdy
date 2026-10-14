#include<bits/stdc++.h>
#define MX 1010
#define INF 1e9
using namespace std;

typedef tuple<int,int,int> tup;
typedef pair<int, int> pii;

int N, M, K;
int st, en;
int a, b, w, p;

vector<pii> adj[MX];
int dist[MX][MX];
int inc[30002];

void dijkstra() {
	priority_queue<tup, vector<tup>, greater<tup>> pq;

	pq.push({ 0, 0, st });
	dist[0][st] = 0;

	int co, nop, cur;
	while (!pq.empty()) {
		tie(co, nop, cur) = pq.top();
		pq.pop();

		if (dist[nop][cur] != co) continue;
		if (nop == N) continue;


		for (const auto& a : adj[cur]) {
			int next = a.first;
			int dco = a.second;

			dco += co;
			if (dco >= dist[nop + 1][next]) continue;
			dist[nop + 1][next] = dco;
			pq.push({ dco, nop + 1, next });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	cin >> st >> en;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> w;
		adj[a].push_back({ b, w });
		adj[b].push_back({ a, w });
	}

	for (int i = 1; i <= K; i++) cin >> inc[i];

	for (int i = 0; i <= 1000; i++) fill(dist[i], dist[i] + 1001, INF);

	dijkstra();

	for (int i = 0; i <= K; i++) {
		int ans = INF;

		for (int nop = 0; nop <= N; nop++) {
			dist[nop][en] += nop * inc[i];
			ans = min(ans, dist[nop][en]);
		}
		cout << ans << '\n';
	}

	return 0;
}