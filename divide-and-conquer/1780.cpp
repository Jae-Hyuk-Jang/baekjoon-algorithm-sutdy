#include<bits/stdc++.h>
#define MX 2200
using namespace std;

int N;
int mat[MX][MX];
int cnt[3];

bool check(int x, int y, int n) {
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (mat[x][y] != mat[i][j]) return false;
		}
	}
	return true;
}

void solve(int x, int y, int z) {
	if (check(x, y, z)) {
		cnt[mat[x][y] + 1] += 1;
		return;
	}
	int n = z / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			solve(x + i * n, y + j * n, n);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mat[i][j];
		}
	}
	solve(0, 0, N);
	for (int i = 0; i < 3; i++) cout << cnt[i] << '\n';

	return 0;
}