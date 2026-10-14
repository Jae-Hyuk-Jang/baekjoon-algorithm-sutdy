#include<bits/stdc++.h>
#define MX 1000001
using namespace std;

int parent[MX];
int sizes[MX];

void init() {
	for (int i = 0; i < MX; i++) {
		parent[i] = -1;
		sizes[i] = 1;
	}
}

int find(int x) {
	if (parent[x] < 0) return x;
	return parent[x] = find(parent[x]);
}

void unite(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) return;
	if (sizes[u] < sizes[v]) swap(u, v);
	parent[v] = u;
	sizes[u] += sizes[v];
	return;
}

int size(int x) {
	return sizes[find(x)];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	init();
	int N; cin >> N;
	while (N--) {
		char c; cin >> c;
		if (c == 'I') {
			int u, v; cin >> u >> v;
			unite(u, v);
		}
		else {
			int n; cin >> n;
			/*for (int i = 1; i <= 4; i++) cout << sizes[i] << ' ';
			cout << '\n';*/
			cout << sizes[find(n)] << '\n';
		}
	}

	return 0;
}