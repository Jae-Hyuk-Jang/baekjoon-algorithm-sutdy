#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MX = 129;

ll N;
int mat[MX][MX];
int wh = 0, bl = 0;

bool check(int len, int x, int y) {
	int flag = mat[x][y];
	for (int i = x; i < x + len; i++) {
		for (int j = y; j < y + len; j++) {
			if (flag != mat[i][j]) return false;
		}
	}
	return true;
}

void addCnt(int val) {
	if (val == 1) bl++;
	else wh++;
	return;
}

void dq(int len, int x, int y) {
	if (len < 1) return;
	if (check(len, x, y)) {
		addCnt(mat[x][y]);
		return;
	}
	int nxt = len / 2;
	dq(nxt, x, y);
	dq(nxt, x + nxt, y);
	dq(nxt, x, y + nxt);
	dq(nxt, x + nxt, y + nxt);
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

	dq(N, 0, 0);
	cout << wh << '\n' << bl;
	return 0;
}