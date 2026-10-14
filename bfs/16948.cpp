#include<bits/stdc++.h>
using namespace std;

int dx[6] = { -2, -2, 0, 0, 2, 2 };
int dy[6] = { -1, 1, -2, 2, -1, 1 };

queue<pair<int, pair<int, int>>> q;
int r1, c1, r2, c2;
int n;

int answer = 1e9;

int mat[201][201];
int processed[201][201];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> r1 >> c1 >> r2 >> c2;

	q.push({ 0, {r1, c1}});
	processed[r1][c1] = true;

	while (!q.empty()) {
		int cx, cy, cnt;
		cx = q.front().second.first;
		cy = q.front().second.second;
		cnt = q.front().first;
		q.pop();

		if (cx == r2 && cy == c2) {
			answer = min(answer, cnt);
		}

		for (int i = 0; i < 6; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (processed[nx][ny]) continue;
			processed[nx][ny] = true;
			q.push({ cnt + 1, {nx, ny} });
		}
	}

	cout << ((answer == 1e9) ? -1 : answer);
	return 0;
}