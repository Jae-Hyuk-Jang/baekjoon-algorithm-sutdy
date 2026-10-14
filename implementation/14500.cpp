#include<bits/stdc++.h>
#define MX 502
using namespace std;

int n, m;
bool vis[MX][MX];
int board[MX][MX];

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int mx, sum;

bool oob(int x, int y) {
	return (x >= n || x < 0 || y >= m || y < 0);
}


void tetromino(int cx, int cy, int cnt) {
	if (cnt == 4) {
		mx = max(mx, sum);
		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		int nx = cx + dx[dir];
		int ny = cy + dy[dir];

		if (oob(nx, ny)) continue;
		if (vis[nx][ny]) continue;
		sum += board[nx][ny];
		vis[nx][ny] = 1;
		tetromino(nx, ny, cnt + 1);
		tetromino(nx, ny, cnt + 1);
		if (cnt == 2) tetromino(cx, cy, cnt + 1);
		sum -= board[nx][ny];
		vis[nx][ny] = 0;
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			sum = board[i][j];
			vis[i][j] = 1;
			tetromino(i, j, 1);
			vis[i][j] = 0;
		}
	}
	cout << mx;
	return 0;
}