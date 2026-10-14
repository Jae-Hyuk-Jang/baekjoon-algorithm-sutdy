#include<bits/stdc++.h>
#define MX 22
#define MNX 222
using namespace std;

int n;
int board[MX][MX];
int id[MX][MX][2];

int dx[] = { 1, 1 };
int dy[] = { 1, -1 };
int cnt[] = { 0, 0 };

void makeGroup(int dir) {
	int x, y;
	cnt[dir] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (board[i][j]) continue;
			if (id[i][j][dir]) continue;
			x = i, y = j;
			id[i][j][dir] = ++cnt[dir];

			while (1) {
				x += dx[dir], y += dy[dir];
				if (x < 1 || y < 1 || x > n || y > n) break;
				if (board[x][y]) continue;
				if (id[x][y][dir]) continue;
				id[x][y][dir] = cnt[dir];
			}
		}
	}
}

set<int> g[MNX];
int par[MNX];
bool chk[MNX];

bool match(int v) {
	for (auto i : g[v]) {
		if (chk[i]) continue;
		chk[i] = true;
		if (par[i] == -1 || match(par[i])) {
			par[i] = v;
			return 1;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int t; cin >> t;
			board[i][j] = 1 - t;
		}
	}

	for (int i = 0; i < 2; i++) makeGroup(i);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (board[i][j]) continue;
			int aid = id[i][j][0];
			int bid = id[i][j][1] + cnt[0];
			g[aid].insert(bid);
		}
	}

	int ret = 0;
	fill(par, par + MNX, -1);
	for (int i = 1; i <= cnt[0]; i++) {
		fill(chk, chk + MNX, 0);
		ret += match(i);
	}
	cout << ret;
	return 0;
}
