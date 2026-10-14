#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

#define X first
#define Y second
#define MX 105


int board[MX][MX];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

deque<pii> dq;
queue<pii> switchDir;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k; cin >> n >> k;
	while (k--) {
		int a, b; cin >> a >> b;
		board[a][b] = 2;
	}

	int l; cin >> l;
	while (l--) {
		int c; char d; cin >> c >> d;
		switchDir.push({ c, d });
	}

	dq.push_front({ 1, 1 });
	int dir = 1;
	int time = 0;

	while (true) {
		dir %= 4;

		auto cur = dq.front();
		board[cur.X][cur.Y] = 1;
		time++;

		int nx = cur.X + dx[dir];
		int ny = cur.Y + dy[dir];

		if (nx < 1 || nx > n || ny < 1 || ny > n) break;
		if (board[nx][ny] == 1) break;

		if (board[nx][ny] != 2) {
			auto tail = dq.back();
			board[tail.X][tail.Y] = 0;
			dq.pop_back();
		}

		auto sd = switchDir.front();
		if (sd.X == time) {
			if (sd.Y == 'L') dir += 1;
			else if (sd.Y == 'D') dir += 3;
			switchDir.pop();
		}
		dq.push_front({ nx, ny });
	}
	cout << time;
	return 0;
}