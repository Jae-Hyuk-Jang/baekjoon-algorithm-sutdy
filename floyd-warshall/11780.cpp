#include<bits/stdc++.h>
#define MX 110
#define INF 1e9
using namespace std;

int n, m;
int mat[MX][MX];
int a, b, c;
vector<int> route[MX][MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		fill(mat[i] + 1, mat[i] + n + 1, INF);
		mat[i][i] = 0;
		route[i][i].push_back(i);
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (mat[a][b] > c) {
			mat[a][b] = c;
			route[a][b].clear();
			route[a][b].push_back(a);
			route[a][b].push_back(b);
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (mat[i][j] > mat[i][k] + mat[k][j]) {
					route[i][j].clear();
					for (const auto& r : route[i][k]) route[i][j].push_back(r);
					route[i][j].pop_back();
					//route[i][j].push_back(k);
					for (const auto& r : route[k][j]) route[i][j].push_back(r);
					mat[i][j] = mat[i][k] + mat[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (mat[i][j] != INF)cout << mat[i][j] << ' ';
			else cout << 0 << ' ';
		}
		cout << '\n';
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (mat[i][j] == 0 || mat[i][j] == INF) cout << 0 << '\n';
			else {
				cout << route[i][j].size() << ' ';
				for (const auto& r : route[i][j]) {
					cout << r << ' ';
				}
				cout << '\n';
			}
		}
	}

	return 0;
}