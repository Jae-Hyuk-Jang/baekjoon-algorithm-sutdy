#include<bits/stdc++.h>
#define MX 101
using namespace std;

int n, m;
int dist[MX];
int route[MX];

void bfs(int x) {
	queue<int> q; q.push(x);

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int i = 1; i <= 6; i++) {
			int next = cur + i;
			if (next > 100) continue;
			int nextDist = dist[cur] + 1;
			int nextPoint = route[next];

			if (dist[nextPoint] == -1) {
				dist[nextPoint] = nextDist;
				q.push(nextPoint);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= 100; i++) {
		route[i] = i;
		dist[i] = -1;
	}

	for (int i = 0; i < n + m; i++) {
		int st, en; cin >> st >> en;
		route[st] = en;
	}

	dist[1] = 0;
	bfs(1);
	cout << dist[100];
	return 0;
}