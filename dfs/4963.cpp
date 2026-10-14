#include<bits/stdc++.h>
#define MX 51
using namespace std;

int w, h;
int mat[MX][MX];
bool processed[MX][MX];

int dx[] = { -1, 1, 0, 0, 1, -1, 1, -1 };
int dy[] = { 0, 0, -1, 1, 1, -1, -1, 1 };

void dfs(int x, int y) {
	if (processed[x][y]) return;
	processed[x][y] = true;

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
		if (!processed[nx][ny] && mat[nx][ny] == 1) dfs(nx, ny);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0) return 0;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> mat[i][j];
				processed[i][j] = 0;
			}
		}

		int ans = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!processed[i][j] && mat[i][j] == 1) {
					dfs(i, j);
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}