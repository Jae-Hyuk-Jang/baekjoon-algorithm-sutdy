#include<bits/stdc++.h>
#define MX 1002
using namespace std;

vector<int> adj[MX];
bool processed[MX];

void dfs(int v) {
	processed[v] = true;
	for (const auto& e : adj[v]) {
		if (!processed[e]) dfs(e);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;

	while (t--) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
			processed[i] = false;
			int v; cin >> v;
			adj[i].push_back(v);
		}

		int answer = 0;
		for (int i = 1; i <= n; i++) {
			if (!processed[i]) {
				answer++;
				dfs(i);
			}
		}
		cout << answer << '\n';
	}

	return 0;
}