#include<bits/stdc++.h>
#define MX 31
using namespace std;


int dx[] = { 0, 0, -1, 1, 0, 0 };
int dy[] = { 1, -1, 0, 0, 0, 0 };
int dh[] = { 0, 0, 0, 0, -1, 1 };

int l, r, c;

char mat[MX][MX][MX];
int dist[MX][MX][MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0) break;
		bool isEscape = false;

		queue<tuple<int, int, int>> q;
		

		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					dist[i][j][k] = 0;
				}
			}
		}


		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					cin >> mat[i][j][k];
					if (mat[i][j][k] == 'S') {
						q.push({ i, j ,k });
						dist[i][j][k] = 0;
					}
					else if (mat[i][j][k] == '.') dist[i][j][k] = -1;
				}
			}
		}

		while (!q.empty()) {
			if (isEscape) break;
			auto cur = q.front(); q.pop();

			int curh, curx, cury;
			tie(curh, curx, cury) = cur;

			for (int i = 0; i < 6; i++) {
				int nh = curh + dh[i];
				int nx = curx + dx[i];
				int ny = cury + dy[i];

				if (nx < 0 || ny < 0 || nx >= r || ny >= c || nh < 0 || nh >= l) continue;
				if (mat[nh][nx][ny] == '#' || dist[nh][nx][ny] > 0) continue;
				dist[nh][nx][ny] = dist[curh][curx][cury] + 1;
				if (mat[nh][nx][ny] == 'E') {
					cout << "Escaped in " << dist[nh][nx][ny] << " minute(s).\n";
					isEscape = true;
					break;
				}
				q.push({ nh, nx, ny });
			}
		}
		if (!isEscape) cout << "Trapped!\n";
	}

	return 0;
}