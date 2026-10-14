#include<bits/stdc++.h>
#define MX 510
#define INF 1e9
using namespace std;
typedef pair<int, int> pii;

int n, m, q;
int cost[MX][MX], dogCost[MX][MX];
int arr[MX];
vector<pii> vec;

void Floyd() {
	for (int i = 0; i < n; i++) {
		int node = vec[i].second;

		for (int s = 1; s <= n; s++) {
			for (int e = 1; e <= n; e++) {
				int dogAttack = max(dogCost[s][node], dogCost[node][e]);
				int curDogAttack = dogCost[s][e];

				if (cost[s][node] + cost[node][e] + dogAttack < cost[s][e] + curDogAttack) {
					cost[s][e] = cost[e][s] = cost[s][node] + cost[node][e];
					dogCost[s][e] = dogCost[e][s] = dogAttack;
				}
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> q;

	for (int i = 1; i <= n; i++) {
		fill(cost[i], cost[i] + n + 1, INF);
		cost[i][i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		vec.push_back({ arr[i], i });
	}
	sort(vec.begin(), vec.end());

	int a, b, c;
	while (m--) {
		cin >> a >> b >> c;
		cost[a][b] = cost[b][a] = c;
		dogCost[a][b] = dogCost[b][a] = max(arr[a], arr[b]);
	}

	Floyd();

	int s, e;
	while (q--) {
		cin >> s >> e;
		cout << ((cost[s][e] == INF) ? -1 : cost[s][e] + dogCost[s][e]) << '\n';
	}

	return 0;
}