#include<bits/stdc++.h>
using namespace std;

#define MX 1002

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

char board[MX][MX];
int dist[MX][MX][12][2];

int N, M, K;

struct pos {
	int x, y, cnt, day;
};

queue<pos> q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	q.push({ 0, 0, 0, 0 });
	dist[0][0][0][0] = 1;

	while (!q.empty()) {
		pos cur = q.front(); q.pop();
		if (cur.x == N - 1 && cur.y == M - 1) {
			cout << dist[cur.x][cur.y][cur.cnt][cur.day];
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (board[nx][ny] == '0') {
				int nw = cur.cnt;
				int nt = 1 - cur.day;
				if (dist[nx][ny][nw][nt] > 0) continue;
				dist[nx][ny][nw][nt] = dist[cur.x][cur.y][cur.cnt][cur.day] + 1;
				q.push({ nx, ny, nw, nt });
			}
			else {
				if (cur.cnt == K) continue;
				if (cur.day == 0) {
					int nw = cur.cnt + 1;
					int nt = 1 - cur.day;
					if (dist[nx][ny][nw][nt] > 0)continue;
					dist[nx][ny][nw][nt] = dist[cur.x][cur.y][cur.cnt][cur.day] + 1;
					q.push({ nx, ny, nw, nt });
				}
				else {
					int nt = 1 - cur.day;
					if (dist[cur.x][cur.y][cur.cnt][nt] > 0)continue;
					dist[cur.x][cur.y][cur.cnt][nt] = dist[cur.x][cur.y][cur.cnt][cur.day] + 1;
					q.push({ cur.x, cur.y, cur.cnt, nt });
				}
			}
		}
	}

	cout << -1;
	return 0;
}