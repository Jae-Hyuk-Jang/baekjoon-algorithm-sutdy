#include<bits/stdc++.h>
#define INF 1e9
using namespace std;
using pii = pair<int, int>;
using ll = long long;

int N;
vector<vector<pii>> adj;
vector<int> deg;
vector<ll> dp;

ll dfs(int u, int p) {
	if (deg[u] == 1 && u != 1) {
		return dp[u] = INF;
	}

	ll sum = 0;
	for (const auto& next : adj[u]) {
		if (next.first == p) continue;
		ll childCost = dfs(next.first, u);
		sum += min<ll>(next.second, childCost);
	}
	return dp[u] = sum;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	int t; cin >> t;
	while (t--) {
		int M; cin >> N >> M;
		adj.assign(N + 1, {});
		deg.assign(N + 1, 0);

		for (int i = 0; i < M; i++) {
			int u, v, w; cin >> u >> v >> w;
			adj[u].push_back({ v,w });
			adj[v].push_back({ u, w });

			deg[u]++; deg[v]++;
		}
		dp.assign(N + 1, 0);
		ll ans = dfs(1, 0);
		cout << ans << '\n';
	}

	return 0;
}