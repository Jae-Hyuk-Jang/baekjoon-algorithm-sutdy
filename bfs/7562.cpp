#include<bits/stdc++.h>
using namespace std;


#define X first
#define Y second
#define MX 305
int dist[MX][MX];
int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int t, n, x, y, xx, yy;
queue<pair<int, int>> q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) fill(dist[i], dist[i] + n, -1);
		cin >> x >> y;
		dist[x][y] = 0;
		q.push({ x, y });
		cin >> xx >> yy;
		while (!q.empty()) {
			auto cur = q.front(); q.pop();

			for (int i = 0; i < 8; i++) {
				int nx = cur.X + dx[i];
				int ny = cur.Y + dy[i];

				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if (dist[nx][ny] >= 0) continue;
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				q.push({ nx, ny });
			}
		}
		cout << dist[xx][yy] << '\n';
	}


	return 0;
}