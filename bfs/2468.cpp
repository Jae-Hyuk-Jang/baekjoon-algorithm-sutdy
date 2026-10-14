#include<bits/stdc++.h>
#define MX 101
using namespace std;

typedef pair<int, int> pii;


int processed[MX][MX];
int mat[MX][MX];


int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

int N;
int safetyArea;
queue<pii> q;

void bfs(int height) {
	while (!q.empty()) {
		pii cur = q.front();
		q.pop();
		processed[cur.first][cur.second] = 1;

		for (int d = 0; d < 4; d++) {
			int nx = cur.first + dx[d];
			int ny = cur.second + dy[d];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (mat[nx][ny] <= height || processed[nx][ny]) continue;
			processed[nx][ny] = 1;
			q.push({ nx, ny });
		}
	}
}


void init() {
	safetyArea = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			processed[i][j] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int height = 0, result = 0;
	cin >> N;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			cin >> mat[x][y];
			if (height < mat[x][y]) height = mat[x][y];
		}
	}

	while (height >= 0) {
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				if (mat[x][y] > height && !processed[x][y]) {
					q.push({ x, y });
					bfs(height);
					safetyArea++;
				}
			}
		}

		if (result < safetyArea) result = safetyArea;

		init();
		height--;
	}

	cout << result;
	return 0;
}