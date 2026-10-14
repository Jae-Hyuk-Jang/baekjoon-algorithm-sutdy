#include<bits/stdc++.h>
using namespace std;
using tu3 = tuple<int, int, int>;

int mat[1000][1000];
int step[10];
int area[10];

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

queue<tu3> q[10];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M, P; cin >> N >> M >> P;

	for (int i = 1; i <= P; i++) cin >> step[i];

	char ch;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> ch;
			if (ch == '.') mat[i][j] = 1;
			else if (ch == '#') mat[i][j] = 0;
			else {
				mat[i][j] = 0;
				q[ch - '0'].push({ i, j, 0 });
				area[ch - '0'] += 1;
			}
		}
	}
	

	while (1) {
		bool proceed = false;
		
		for (int i = 1; i <= P; i++) {
			queue<tu3> nxtq;

			while (!q[i].empty()) {
				int curx, cury, curstep;
				tie(curx, cury, curstep) = q[i].front();
				q[i].pop();

				if (curstep >= step[i]) {
					nxtq.push({ curx, cury, 0 });
					continue;
				}


				for (int dir = 0; dir < 4; dir++) {
					int x = curx + dx[dir];
					int y = cury + dy[dir];
					if (x < 0 || x >= N || y < 0 || y >= M) continue;
					if (!mat[x][y]) continue;
					q[i].push({ x, y, curstep + 1 });
					mat[x][y] = 0;
					area[i]++;
					proceed = true;
				}
			}

			q[i] = nxtq;
		}

		if (!proceed) break;
	}


	for (int i = 1; i <= P; i++) cout << area[i] << ' ';

	return 0;
}