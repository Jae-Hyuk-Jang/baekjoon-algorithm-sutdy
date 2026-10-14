#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

#define X first
#define Y second

const int INF = 0x7f7f7f7f;
const int MX = 55;

int n, m;
int ans = INF;
int board[MX][MX];
int dist[MX][MX];

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

vector<pii> v;
queue<pii> q;

vector<int> brute;

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				v.push_back({ i, j });
				board[i][j] = 0;
			}
		}
	}
}

void solve() {
	do {
		int t = 0; 
		for (int i = 0; i < n; i++) fill(dist[i], dist[i] + n, -1);

		for (int i = 0; i < v.size(); i++) {
			if (!brute[i]) {
				q.push({ v[i].X, v[i].Y });
				dist[v[i].X][v[i].Y] = 0;
			}
		}

		while (!q.empty()) {
			auto cur = q.front(); q.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
				if (board[nx][ny] != 0 || dist[nx][ny] >= 0) continue;
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				t = max(t, dist[nx][ny]);
				q.push({ nx, ny });
			}
		}

		bool flag = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == 0 && dist[i][j] == -1) flag = false;
			}
		}

		if (flag) ans = min(ans, t);
	} while (next_permutation(brute.begin(), brute.end()));

	cout << ((ans == INF) ? -1 : ans);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input();

	brute.resize(v.size());

	for (int i = m; i < v.size(); i++) brute[i] = 1;

	solve();

	return 0;
}

