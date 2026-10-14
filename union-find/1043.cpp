#include<bits/stdc++.h>
#define MX 51
using namespace std;

int N, M;
vector<int> adj[MX];
bool know[MX];
int parent[MX];
bool party[MX];

void init() {
	for (int i = 0; i <= N; i++) parent[i] = i;
}

int find(int idx) {
	if (parent[idx] == idx) return idx;
	return parent[idx] = find(parent[idx]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool same(int a, int b) {
	return find(a) == find(b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	init();
	int num, n; cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> n;
		parent[n] = 0;
	}

	for (int i = 0; i < M; i++) {
		cin >> num;
		int p = 0;
		if (num != 0) {
			cin >> p;
			adj[i].push_back(p);
		}
		num--;
		while (num--) {
			cin >> n;
			adj[i].push_back(n);
			if (!same(p, n)) unite(p, n);
		}
	}

	/*for (int i = 0; i <= N; i++) {
		cout << i << "'s parent >> " << parent[i] << endl;
	}*/

	int answer = 0;
	for (int i = 0; i < M; i++) {
		if (find(adj[i][0]) == 0) continue;
		answer++;
	}
	cout << answer;

	return 0;
}