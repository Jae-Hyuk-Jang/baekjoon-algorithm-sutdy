#include<bits/stdc++.h>
using namespace std;

#define MX 1002

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

char board[MX][MX];
int dist[MX][MX][12];
int n, m, K;
queue<tuple<int, int, int>> q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> K;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	dist[0][0][0] = 1;
	q.push({ 0, 0, 0 });

	while (!q.empty()) {
		int x, y, w;
		tie(x, y, w) = q.front(); q.pop();
		if (x == n - 1 && y == m - 1) {
			cout << dist[x][y][w];
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			int nw = w;
			if (board[nx][ny] == '1') nw++;
			if (nw > K || dist[nx][ny][nw] > 0) continue;
			dist[nx][ny][nw] = dist[x][y][w] + 1;
			q.push({ nx, ny, nw });
		}
	}

	cout << -1;
	return 0;
}