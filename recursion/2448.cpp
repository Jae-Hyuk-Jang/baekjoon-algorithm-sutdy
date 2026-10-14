#include<bits/stdc++.h>
using namespace std;

#define MX 3073

char mat[MX][MX * 3];
int N;

void re(int n, int x, int y) {
	if (n == 3) {
		mat[x][y] = mat[x+1][y-1] = mat[x+1][y+1] = '*';
		for (int j = y - 2; j <= y + 2; j++) mat[x + 2][j] = '*';
		return;
	}

	re(n >> 1, x, y);
	re(n >> 1, x + (n >> 1), y - (n >> 1));
	re(n >> 1, x + (n >> 1), y + (n >> 1));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N; j++) {
			mat[i][j] = ' ';
		}
	}

	re(N, 0, N - 1);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N - 1; j++) {
			cout << mat[i][j];
		}
		cout << '\n';
	}


	return 0;
}