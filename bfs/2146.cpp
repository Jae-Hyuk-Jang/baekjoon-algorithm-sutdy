#include<bits/stdc++.h>
#define MX 101
#define INF 1e9
using namespace std;

int mat[MX][MX];
bool processed[MX][MX];
int dist[MX][MX];
int N;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int ans = INF;
queue<tuple<int, int, int>> q;

void bfs(int index) {
	memset(dist, 0, sizeof(dist));
	while (!q.empty()) {
		int x, y, idx;
		tie(x, y, idx) = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (dist[nx][ny] == 0) {
				if (mat[nx][ny] == 0) {
					dist[nx][ny] = dist[x][y] + 1;
					q.push({ nx, ny, mat[nx][ny] });
				}
				else if (index != mat[nx][ny]) {
					ans = min(ans, dist[x][y]);
				}
			}
		}
	}
}

void boundary(int x, int y) {
	if (processed[x][y]) return;
	processed[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (!processed[nx][ny] && mat[nx][ny]) {
			processed[nx][ny] = true;
			q.push({ nx, ny, mat[nx][ny]});
			bfs(mat[nx][ny]);
			return;
		}
		if (!processed[nx][ny] && mat[nx][ny]) {
			boundary(nx, ny);
		}
	}
}



void dfs(int x, int y, int cnt) {
	if (processed[x][y]) return;
	processed[x][y] = true;
	mat[x][y] = cnt;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (!processed[nx][ny] && mat[nx][ny] != 0) dfs(nx, ny, cnt);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mat[i][j];
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!processed[i][j] && mat[i][j]) dfs(i, j, ++cnt);
		}
	}

	memset(processed, 0, sizeof(processed));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (mat[i][j] == 0 && !processed[i][j]) {
				boundary(i, j);
			}
		}
	}

	cout << ans;

	return 0;
}