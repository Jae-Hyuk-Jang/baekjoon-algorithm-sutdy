#include<bits/stdc++.h>
using namespace std;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

int mat[5][5];
set<int> ans;

void dfs(int x, int y, int cnt, int num) {
	int tmp = mat[x][y];
	for (int i = 0; i < 5 - cnt; i++) {
		tmp *= 10;
	}
	num += tmp;
	if (cnt == 5) {
		ans.insert(num);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
		dfs(nx, ny, cnt + 1, num);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> mat[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(i, j, 0, 0);
		}
	}
	cout << ans.size();

	return 0;
}