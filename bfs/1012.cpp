#include<bits/stdc++.h>
using namespace std;

int n, m, k;
int mat[51][51];


int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int cnt = 0;


void dfs(int x, int y) {
	if (mat[x][y] == 2) return;
	mat[x][y] = 2;

	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;

		if (nx >= n || ny >= m || nx < 0 || ny < 0) continue;
		if (mat[nx][ny] == 0 || mat[nx][ny] == 2) continue;
		dfs(nx, ny);
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while (t--) {
		cin >> m >> n >> k;
		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				mat[i][j] = 0;
			}
		}

		int x, y;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			mat[y][x] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j] == 1) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}