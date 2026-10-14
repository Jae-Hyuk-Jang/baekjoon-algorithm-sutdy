#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

#define X first
#define Y second

#define MX 101

int board[MX][MX];
bool vis[MX][MX];
vector<pii> adj[MX][MX];

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int n, m;
bool oob(int a, int b) { return a < 1 || a > n || b < 1 || b > n; }

bool is_conn(pii nxt) {
	for (int i = 0; i < 4; i++) {
		int nx = nxt.X + dx[i];
		int ny = nxt.Y + dy[i];
		if (oob(nx, ny)) continue;
		if (vis[nx][ny]) return 1;
	}
	return 0;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	while (m--) {
		int x, y, a, b; cin >> x >> y >> a >> b;
		adj[x][y].push_back({ a, b });
	}

	queue<pii> q;
	board[1][1] = 1;
	vis[1][1] = 1;
	q.push({ 1, 1 });

	while (!q.empty()) {
		auto cur = q.front(); 
		q.pop();
		for (auto nxt : adj[cur.X][cur.Y]) {
			if (vis[nxt.X][nxt.Y]) continue;
			if (is_conn(nxt)) {
				vis[nxt.X][nxt.Y] = 1;
				q.push({ nxt.X, nxt.Y });
			}
			board[nxt.X][nxt.Y] = 1;
		}

		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (oob(nx, ny) || vis[nx][ny] || board[nx][ny] == 0) continue;
			vis[nx][ny] = 1;
			q.push({ nx, ny });
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans += board[i][j];
		}
	}
	cout << ans;

	return 0;
}