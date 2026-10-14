#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

#define MX 810
#define INF 1000000000
#define out 400
using namespace std;

int result;
int c[MX][MX], f[MX][MX], parent[MX];
vector<int> adj[MX];

int N, P;

void maxFlow() {
	while (1) {
		fill(parent, parent + MX, -1);
		queue<int> q;

		q.push(1);

		while (!q.empty()) {
			int x = q.front();
			q.pop();

			for (int& y : adj[x]) {
				if (c[x][y] - f[x][y] > 0 && parent[y] == -1) {
					q.push(y);
					parent[y] = x;
					if (y == 2) break;
				}
			}
		}

		if (parent[2] == -1) break;

		for (int i = 2; i != 401; i = parent[i]) {
			f[parent[i]][i] += 1;
			f[i][parent[i]] -= 1;
		}
		result += 1;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> P;
	int a, b;

	for (int i = 1; i <= N; i++) {
		adj[i].push_back(i + out);
		adj[i + out].push_back(i);
		c[i][i + out] = 1;
	}

	for (int i = 0; i < P; i++) {
		cin >> a >> b;
		adj[a + out].push_back(b);
		adj[b].push_back(a + out);
		c[a + out][b] = 1;

		adj[a].push_back(b + out);
		adj[b + out].push_back(a);
		c[b + out][a] = 1;

	}

	maxFlow();
	cout << result << endl;

	return 0;
}