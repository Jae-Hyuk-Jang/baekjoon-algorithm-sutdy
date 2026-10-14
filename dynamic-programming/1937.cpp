#include<bits/stdc++.h>
#define MX 505
using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int dp[MX][MX];
int board[MX][MX];
int n;

bool oob(int i, int j) {
	return i < 0 || i >= n || j < 0 || j >= n;
}

int go(int x, int y) {
	if (dp[x][y] != -1) return dp[x][y];
	
	dp[x][y] = 1;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (oob(nx, ny) || board[x][y] >= board[nx][ny])continue;
		dp[x][y] = max(dp[x][y], go(nx, ny) + 1);
	}
	return dp[x][y];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			dp[i][j] = -1;
		}
	}

	int mx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mx = max(mx, go(i, j));
		}
	}
	cout << mx;
	return 0;
}