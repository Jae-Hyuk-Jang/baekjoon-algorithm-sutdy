#include<bits/stdc++.h>
#define MX 500001
using namespace std;

int parent[MX];
int n, m;

int find(int x) {
	if (parent[x] < 0) return x;
	return parent[x] = find(parent[x]);
}

bool issame(int u, int v) {
	return find(u) == find(v);
}

bool unite(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) return false;
	if (u > v) swap(u, v);
	parent[u] = v;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) parent[i] = -1;
	int answer = 0;
	int cnt = 0;
	while (m--) {
		++cnt;
		int u, v; cin >> u >> v;
		if (!unite(u, v) && answer ==0) {
			answer = cnt;
		}
	}
	
	cout << answer;
	return 0;
}