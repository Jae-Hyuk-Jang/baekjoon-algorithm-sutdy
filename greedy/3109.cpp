#include<bits/stdc++.h>
using namespace std;

int mat[10001][501];
int R, C;
int cnt;

int dc[3] = { 1, 1, 1 };
int dr[3] = { -1, 0, 1 };

bool dfs(int r, int c) {
	if (c == C - 1) {
		cnt++;
		return true;
	}
	
	mat[r][c] = 1;
	for (int i = 0; i < 3; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr >= 0 && nr < R && nc >= 0 && nc < C && !mat[nr][nc]) {
			if(dfs(nr, nc)) return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;
	
	for (int i = 0; i < R; i++) {
		string in; cin >> in;
		for (int j = 0; j < C; j++) {
			if (in[j] == '.') mat[i][j] = 0;
			else mat[i][j] = 1;
		}
	}

	for (int i = 0; i < R; i++) {
		dfs(i, 0);
	}

	cout << cnt;


	return 0;
}