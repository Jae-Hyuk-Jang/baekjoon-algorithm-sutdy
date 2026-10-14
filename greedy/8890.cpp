#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

#define MX 2001

int n, c, m;
vector<pii> adj[MX];
int state[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> c >> m;
	for (int i = 0; i < m; i++) {
		int s, e, d; cin >> s >> e >> d;
		adj[e].push_back({ s, d });
	}

	for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());

	int answer = 0;
	for (int en = 1; en <= n; en++) {
		for (const auto& cur : adj[en]) {
			int st = cur.first;
			int box = cur.second;
			for (int i = st; i < en; i++) {
				box = min(box, c - state[i]);
			}
			answer += box;
			for (int i = st; i < en; i++) {
				state[i] += box;
			}
		}
	}
	//for (int i = 1; i <= n; i++) cout << state[i] << ' ';
	//cout << '\n';
	cout << answer;
	return 0;
}