#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int mat[9][9];
bool processed[9][9];

int n, m, ans = 0;
int virus = 0, free_cells = 0;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
vector<pii> frees;

int bfs() {
	queue<pii> q;
	memset(processed, 0, sizeof(processed));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 2) q.push({ i, j });		
		}
	}

	int ret = 0;
	while (!q.empty()) {
		pii cur = q.front();
		processed[cur.first][cur.second] = 1;
		q.pop();
		ret++;
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (mat[nx][ny] != 0 || processed[nx][ny]) continue; 
			processed[nx][ny] = 1;
			q.push({ nx, ny });
		}
	}
	return ret;
}

void dfs(int k, int idx) {
	if (k == 3) {
		int tmp = bfs();
		ans = max(ans, free_cells - 3 - tmp + virus);
		return;
	}

	for (int i = idx; i < free_cells; i++) {
		mat[frees[i].first][frees[i].second] = 1;
		dfs(k + 1, i + 1);
		mat[frees[i].first][frees[i].second] = 0;
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);			


	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 0) {
				free_cells++;
				frees.push_back({ i, j });
			}
			else if (mat[i][j] == 2) {
				virus++;
			}
		}
	}
	dfs(0, 0);
	cout << ans;

	return 0;
}