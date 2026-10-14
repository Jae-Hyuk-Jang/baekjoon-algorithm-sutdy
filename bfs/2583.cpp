#include<bits/stdc++.h>
#define MX 101
using namespace std;
typedef pair<int, int> pii;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int mat[MX][MX];
int m, n, k;
bool processed[MX][MX];
queue<pii> q;
vector<int> ans;

void init() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			mat[i][j] = 0;
			processed[i][j] = 0;
		}
	}
}

int bfs(int i, int j) {
	int cnt = 0;

	cnt++;
	q.push({ i, j });
	processed[i][j] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();


		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if (processed[nx][ny]) continue;
			processed[nx][ny] = 1;
			if (mat[nx][ny]) continue;
			q.push({ nx, ny });
			cnt++;
		}
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n >> k;
	init();

	int rs, re, cs, ce;
	for (int t = 0; t < k; t++) {
		cin >> cs >> rs >> ce >> re;
		for (int x = rs; x < re; x++) {
			for (int y = cs; y < ce; y++) {
				mat[x][y] = 1;
			}
		}
	}


	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!processed[i][j] && !mat[i][j]) {
				int cnt = bfs(i, j);
				ans.push_back(cnt);
			}
		}
	}


	/*for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << mat[i][j] << ' ';
		}
		cout << endl;
	}*/

	cout << ans.size() << '\n';
	sort(ans.begin(), ans.end());
	for (const auto& c : ans) cout << c << ' ';

	return 0;
}