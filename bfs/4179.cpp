#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define MX 1002

string board[MX];
int dist1[MX][MX];
int dist2[MX][MX];
int n, m;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		fill(dist1[i], dist1[i] + m, -1);
		fill(dist2[i], dist2[i] + m, -1);
	}

	queue<pair<int, int>> q1, q2;

	for (int i = 0; i < n; i++) {
		cin >> board[i];
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'F') {
				q1.push({ i, j });
				dist1[i][j] = 0;
			}
			if (board[i][j] == 'J') {
				q2.push({ i, j });
				dist2[i][j] = 0;
			}
		}
	}

	while (!q1.empty()) {
		auto cur = q1.front(); q1.pop();
		for (int d = 0; d < 4; d++) {
			int nx = cur.X + dx[d];
			int ny = cur.Y + dy[d];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
			if (dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
			q1.push({ nx, ny });
		}
	}


	while (!q2.empty()) {
		auto cur = q2.front(); q2.pop();
		for (int d = 0; d < 4; d++) {
			int nx = cur.X + dx[d];
			int ny = cur.Y + dy[d];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) { 
				cout << dist2[cur.X][cur.Y] + 1;
				return 0;
			}
			if (dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1) continue; 
			dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
			q2.push({ nx,ny });
		}
	}
	cout << "IMPOSSIBLE"; 

	return 0;
}