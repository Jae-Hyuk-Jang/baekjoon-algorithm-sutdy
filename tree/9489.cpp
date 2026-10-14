#include<bits/stdc++.h>
using namespace std;

int graph[1000001];
vector<int> idx;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	while (cin >> n >> k) {
		if (n == 0 && k == 0) break;

		int parent_idx = -1, before = 0, ans = 0;
		for (int i = 0; i < n; i++) {
			int node; cin >> node;
			idx.push_back(node);

			if (i == 0) {
				before = node;
				graph[node] = -1;
			}
			else {
				if (before + 1 == node) {
					graph[node] = idx[parent_idx];
					before = node;
				}
				else {
					before = node;
					graph[node] = idx[++parent_idx];
				}
			}
		}
		if (k == idx[0]) {
			cout << 0 << '\n';
		}
		else {
			for (int node : idx) {
				if (graph[graph[node]] == graph[graph[k]] && graph[node] != graph[k] ) ans++;
			}
			cout << ans << '\n';
		}
		idx.clear();
		memset(graph, 0, sizeof(graph));
	}


	return 0;
}