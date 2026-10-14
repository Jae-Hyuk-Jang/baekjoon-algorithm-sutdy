#include<bits/stdc++.h>
#define MX 410
#define INF 1e9
using namespace std;

int v, e;
int mat[MX][MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e;
	
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i == j) mat[i][j] = 0;
			else mat[i][j] = INF;
		}
	}

	for (int i = 0; i < e; i++) {
		int a, b, c; cin >> a >> b >> c;
		mat[a][b] = c;
	}


	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
			}
		}
	}

	int ans = INF;
	for (int i = 1; i <= v; i++) {
		for (int j = i+1; j <= v; j++) {
			if (mat[i][j] != INF && mat[j][i] != INF) {
				ans = min(ans, mat[i][j] +mat[j][i]);
			}
		}
	}
	cout << ((ans == INF) ? -1 : ans);
	
	return 0;
}