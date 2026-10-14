#include<bits/stdc++.h>
using namespace std;

int mat[1001][1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, Q;  cin >> n >> m >> Q;
	int total = n * m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			mat[i][j] = 1;
		}
	}

	queue<pair<int, int>> q;
	while (Q--) {
		int num; cin >> num;
		int dy, dx, y, x;
		if (num == 1) {
			cin >> dy >> dx >> y >> x;
			if (mat[y][x]) {
				q.push({ y, x });
				mat[y][x] = 0;
				total--;
				while (!q.empty()) {
					int cy = q.front().first;
					int cx = q.front().second;
					q.pop();

					int ny = dy + cy;
					int nx = dx + cx;

					if (ny < 1 || nx < 1 || ny > n || nx > m) break;
					if (!mat[ny][nx]) break;
					mat[ny][nx] = 0;
					total--;
					q.push({ ny, nx });
				}
			}
			while (!q.empty()) q.pop();
		}
		else if (num == 2) {
			cin >> y >> x;
			cout << ((mat[y][x]) ? 0 : 1) << '\n';
		}
		else {
			cout << total << '\n';
		}
	}
	return 0;
}