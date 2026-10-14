#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
using pii = pair<int, int>;

#define X first
#define Y second

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
const int MX = 120;

char board[MX][MX];
int vis[MX][MX];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int h, w;  cin >> h >> w;
		queue<pii> q;
		queue<pii> door[26];

		int key[26] = {};
		int cnt = 0;

		for (int i = 0; i <= h + 1; i++) {
			fill(vis[i], vis[i] + w + 2, 0);
			fill(board[i], board[i] + w + 2, 0);
		}

		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> board[i][j];
			}
		}
		string keystr; cin >> keystr;

		for (const auto& c : keystr) if(c != '0') key[c - 'a'] = 1;
		q.push({ 0, 0 });
		vis[0][0] = 1;

		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx > h + 1 || ny < 0 || ny > w + 1)continue;
				if (vis[nx][ny] || board[nx][ny] == '*') continue;
				vis[nx][ny] = 1;

				if (board[nx][ny] >= 'a' && board[nx][ny] <= 'z') {
					int k = board[nx][ny] - 'a';
					key[k] = 1;
					while (!door[k].empty()) {
						auto ndoor = door[k].front(); door[k].pop();
						q.push({ ndoor.X, ndoor.Y });
					}
				}
				else if (board[nx][ny] >= 'A' && board[nx][ny] <= 'Z') {
					int k = board[nx][ny] + 32 - 'a';
					if (!key[k]) {
						door[k].push({ nx, ny });
						continue;
					}
				}
				else if (board[nx][ny] == '$') cnt++;
				q.push({ nx, ny });
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}