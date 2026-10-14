#include<bits/stdc++.h>
#define MX 10005
using namespace std;

int n;
int a[MX], d1[MX], d2[MX];

vector<int> adj[MX];

void dfs(int cur, int par) {
	d1[cur] = a[cur];
	d2[cur] = 0;
	for (int nxt : adj[cur]) {
		if (par == nxt) continue;
		dfs(nxt, cur);
		d1[cur] += d2[nxt];
		d2[cur] += max(d1[nxt], d2[nxt]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);
	cout << max(d1[1], d2[1]);

	return 0;
}