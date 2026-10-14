#include<iostream>
#include<algorithm>
#define MX 201
using namespace std;

int N, M;
bool mat[MX][MX];
int parent[MX];
int travel[1001];

int find(int x) {
	if (parent[x] < 0) return x;
	return parent[x] = find(parent[x]);
}

void unite(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) return;
	if (u < v) swap(u, v);
	parent[u] = v;
	return;
}

bool issame(int u, int v) {
	return find(u) == find(v);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) parent[i] = -1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> mat[i][j];
			if (mat[i][j]) unite(i, j);
		}
	}
	
	for (int i = 0; i < M; i++) cin >> travel[i];

	for (int i = 1; i < M; i++) {
		if (!issame(travel[i - 1], travel[i])) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}