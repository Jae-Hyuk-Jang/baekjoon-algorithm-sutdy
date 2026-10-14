#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define MX 1002

int n, m, tc;

int board[MX][MX];
int visF[MX][MX];
int visS[MX][MX];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	for (int test_case = 0; test_case < tc; test_case++) {
		bool escape = false;
		queue<pair<int, int>> qf, qs;
		cin >> m >> n;
		for (int i = 0; i < n; i++) {
			fill(visF[i], visF[i] + m, 0);
			fill(visS[i], visS[i] + m, 0);
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				char c; cin >> c;
				if (c == '#') board[i][j] = -1;
				else {
					if (c == '@') {
						qs.push({ i, j });
						visS[i][j] = 1;
					}
					else if (c == '*') {
						qf.push({ i, j });
						visF[i][j] = 1;
					}
					board[i][j] = 0;
				}
			}
		}

		while (!qf.empty()) {
			auto v = qf.front(); qf.pop();
			for (int k = 0; k < 4; k++) {
				int nx = v.x + dx[k];
				int ny = v.y + dy[k];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (board[nx][ny] == -1) continue;
				if (visF[nx][ny]) continue;
				visF[nx][ny] = visF[v.x][v.y] + 1;
				qf.push({ nx, ny });
			}
		}

		while (!qs.empty() && (!escape)) {
			auto v = qs.front(); qs.pop();
			for (int k = 0; k < 4; k++) {
				int nx = v.x + dx[k];
				int ny = v.y + dy[k];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
					cout << visS[v.x][v.y] << '\n';
					escape = true;
					break;
				}
				if (board[nx][ny] == -1) continue;
				if (visS[nx][ny]) continue;
				if (visF[nx][ny] != 0 && visF[nx][ny] <= visS[v.x][v.y] + 1) continue;
				visS[nx][ny] = visS[v.x][v.y] + 1;
				qs.push({ nx, ny });
			}
		}
		if (!escape) cout << "IMPOSSIBLE" << '\n';
	}

	return 0;
}