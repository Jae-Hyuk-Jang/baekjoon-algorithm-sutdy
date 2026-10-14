#include<bits/stdc++.h>
#define MX 301
using namespace std;

int N, M;
int mat[MX][MX];
int temp[MX][MX];
bool processed[MX][MX];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int year = 0;

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			processed[i][j] = false;
		}
	}
}

void dfs(int x, int y) {
	if (processed[x][y]) return;
	processed[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
		if (processed[nx][ny]) continue;
		if (mat[nx][ny] == 0) continue;

		dfs(nx, ny);
	}
}

bool checkDivide() {
	init();
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (mat[i][j] != 0 && !processed[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	//cout << cnt << endl;
	if (cnt > 1) return true;
	else if (cnt == 0) {
		year = 0;
		return true;
	}
	return false;
}

void melted() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			temp[i][j] = mat[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (mat[i][j] != 0) {
				//cout << mat[i][j] << ' ';
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
					//cout << mat[nx][ny]<< ' ';
					if (mat[nx][ny] == 0 && temp[i][j] > 0) {
						temp[i][j]--;
					}
				}
				//cout << temp[i][j] << endl;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			mat[i][j] = temp[i][j];
		}
	}
	year++;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> mat[i][j];
		}
	}


	/*melted();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout <<  mat[i][j] << ' ';
		}
		cout << endl;
	}*/
	while (1) {

		if (checkDivide()) break;
		//cout << "here" << endl;
		melted();
		/*for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cout << mat[i][j] << ' ';
			}
			cout << endl;
		}*/
	}

	cout << year << '\n';

	return 0;
}


/*
5 7
0 0 0 0 0 0 0
0 2 4 5 3 0 0
0 3 0 2 5 2 0
0 7 6 2 4 0 0
0 0 0 0 0 0 0

2
*/