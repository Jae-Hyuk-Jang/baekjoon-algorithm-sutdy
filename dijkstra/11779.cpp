#include <bits/stdc++.h>
using namespace std;

#define MX 1001
#define INF 1e9

int N, M;
int st, en;
vector<pair<int, int>> adj[MX];
bool processed[MX];
int dist[MX];
int parent[MX];

priority_queue<pair<int, int>> pq;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	int a, b, e;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> e;
		adj[a].push_back({ b, e });
	}
	cin >> st >> en;

	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
		parent[i] = -1;
	}
	dist[st] = 0;

	pq.push({ 0, st });

	while (!pq.empty()) {
		int a = pq.top().second; 
		pq.pop();

		if (processed[a]) continue;
		processed[a] = true;

		for (auto u : adj[a]) {
			int b = u.first, w = u.second;
			if (dist[a] + w < dist[b]) {
				dist[b] = dist[a] + w;
				pq.push({ -dist[b], b });
				parent[b] = a;
			}
		}
	}

	cout << dist[en];
	cout << '\n';
	//for (int i = 1; i <= N; i++) cout << parent[i] << ' ';
	int cnt = 0;

	stack<int> st;
	for (int i = en; i != -1; i = parent[i]) {
		st.push(i);
		cnt++;
	}
	cout << cnt << '\n';

	while(!st.empty()) {
		cout << st.top() << ' ';
		st.pop();
	}

	return 0;
}