#include<bits/stdc++.h>
#define MX 100002
using namespace std;
using ll = long long;

const ll INF = 1e11;

int N, M, a, b;
vector<pair<int, int>> adj[MX];
priority_queue<pair<ll, int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
ll dist[MX];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		adj[a].push_back({ i, b });
		adj[b].push_back({ i, a });
	}

	fill(dist, dist + MX, INF);

	const int MOD = M;
	pq.push({ 0, 1 });
	dist[1] = 0;

	while (!pq.empty()) {
		ll cd = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] != cd) continue;
		for (auto next : adj[cur]) {
			ll rmd = next.first;
			int nxt = next.second;
			ll nd = (rmd - cd) % MOD;
			if (nd < 0) nd += MOD;
			nd += cd + 1;
			if (nd >= dist[nxt]) continue;
			dist[nxt] = nd;
			pq.push({ nd, nxt });
		}
	}
	cout << dist[N];
	return 0;
}