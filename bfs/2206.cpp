#include<bits/stdc++.h>
using namespace std;

#define MX 1000

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

char board[MX][MX];
int dist[MX][MX][2];

int n, m;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			dist[i][j][0] = dist[i][j][1] = -1;
		}
	}

	dist[0][0][0] = dist[0][0][1] = 1;
	queue<tuple<int, int, int>> q;
	q.push({ 0, 0, 0 });

	while (!q.empty()) {
		int x, y, broken;
		tie(x, y, broken) = q.front(); q.pop();
		if (x == n - 1 && y == m - 1) {
			cout << dist[x][y][broken];
			return 0;
		}
		int next = dist[x][y][broken] + 1;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (board[nx][ny] == '0' && dist[nx][ny][broken] == -1) {
				dist[nx][ny][broken] = next;
				q.push({ nx, ny, broken });
			}

			if (!broken && board[nx][ny] == '1' && dist[nx][ny][1] == -1) {
				dist[nx][ny][1] = next;
				q.push({ nx, ny, 1 });
			}
		}
	}

	cout << -1;
	return 0;
}