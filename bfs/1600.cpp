#include<bits/stdc++.h>
#define MX 201
using namespace std;

int mat[MX][MX];
int dist[31][MX][MX];

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

int dhx[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dhy[] = { 1, -1, 2, -2, 2, -2, 1, -1 };

queue <tuple<int, int, int>> q;
int N, M, K;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> K >> M>> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mat[i][j];
		}
	}
	q.push({ 0, 0, 0 });
	dist[0][0][0] = 1;

	while (!q.empty()) {
		int k, x, y;
		tie(k, x, y) = q.front(); q.pop();

		if (k < K) {
			for (int i = 0; i < 8; i++) {
				int nx = x + dhx[i];
				int ny = y + dhy[i];

				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (mat[nx][ny] || dist[k+1][nx][ny]) continue;
				dist[k + 1][nx][ny] = dist[k][x][y] + 1;
				q.push({ k + 1, nx, ny });
			}
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (mat[nx][ny] || dist[k][nx][ny]) continue;
			dist[k][nx][ny] = dist[k][x][y] + 1;
			q.push({ k, nx, ny });
		}
	}

	int ans = 1e9;
	for (int i = 0; i < K + 1; i++) {
		if (dist[i][N - 1][M - 1]) ans = min(ans, dist[i][N - 1][M - 1]);
	}
	cout << ((ans == 1e9) ? -1 : ans - 1);

	return 0;
}