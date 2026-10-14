#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

bool mask[25];
string board[5];

int ans;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	for (int i = 0; i < 5; i++) cin >> board[i];
	fill(mask + 7, mask + 25, true);

	do {
		queue<pii> q;
		int da = 0, adj = 0;
		bool isp7[5][5] = {}, processed[5][5] = {};

		for (int i = 0; i < 25; i++) {
			if (!mask[i]) {
				int x = i / 5, y = i % 5;
				isp7[x][y] = true;
				if (q.empty()) {
					q.push({ x, y });
					processed[x][y] = true;
				}
			}
		}

		while (!q.empty()) {
			int x, y; tie(x, y) = q.front(); q.pop();
			adj++;
			da += (board[x][y] == 'S');
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k], ny = y + dy[k];
				if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
				if (processed[nx][ny] || !isp7[nx][ny]) continue;
				q.push({ nx, ny });
				processed[nx][ny] = true;
			}
		}


		ans += (adj >= 7 && da >= 4);

	} while (next_permutation(mask, mask + 25));
	cout << ans;
	return 0;
}