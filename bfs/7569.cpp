#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define MX 101
using namespace std;

struct pos{
	int x, y, h;
};

int M, N, K;
int mat[MX][MX][MX];
bool processed[MX][MX][MX];
int cnt = 0;

int dx[] = { 0, 0, 1, -1, 0, 0 };
int dy[] = { 0, 0, 0, 0, -1, 1 };
int dh[] = { 1, -1, 0, 0, 0, 0 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<pos> vec;
	cin >> M >> N >> K;
	for(int k = 0 ; k < K; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> mat[i][j][k];
				if (mat[i][j][k] == 1) {
					vec.push_back({ i, j, k });
				}
				else if (mat[i][j][k] == 0) {
					cnt++;
				}
			}
		}
	}

	/*for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cout << mat[i][j];
		}
		cout << endl;
	}*/


	queue<pair<pos, int>> q;
	for (auto v : vec) {
		int x = v.x;
		int y = v.y;
		int h = v.h;
		q.push({ {x, y, h}, 0 });
		processed[x][y][h] = true;
	}

	int Answer = -1;
	while (!q.empty()) {
		int x = q.front().first.x;
		int y = q.front().first.y;
		int h = q.front().first.h;
		int day = q.front().second;
		q.pop();

		if (cnt == 0) {
			Answer = day;
		}

		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nh = h + dh[i];

			if (nx > -1 && ny > -1 && nx < N && ny < M 
				&& nh > -1 && nh < K
				&& !processed[nx][ny][nh] && mat[nx][ny][nh] == 0) {
				processed[nx][ny][nh] = true;
				cnt--;
				q.push({ {nx, ny, nh}, day + 1 });
			}

		}
	}
	cout << Answer;

	return 0;
}