#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define MX 100001
#define INF 1e12

int N, M, K;
vector<pair<int, ll>> adj[MX];
bool processed[MX];
ll dist[MX];

priority_queue<pair<int, ll>> pq;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	int a, b; ll e;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> e;
		adj[b].push_back({ a, e });
	}
	
	for (int i = 1; i <= N; i++) dist[i] = INF;

	int k = 0;
	for (int i = 0; i < K; i++) {
		cin >> k;
		dist[k] = 0;
		pq.push({ 0, k });
	}

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
				
			}
		}
	}

	ll answer = 0, idx = 0;
	for (int i = 1; i <= N; i++) {
		if (answer < dist[i]) {
			answer = dist[i];
			idx = i;
		}
	}

	cout << idx << '\n' << answer;
	

	return 0;
}