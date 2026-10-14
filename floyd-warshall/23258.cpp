#include<bits/stdc++.h>
#define MX 301
#define INF 200000
using namespace std;

int N, Q;
int mat[MX][MX][MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> mat[0][i][j];
			if (mat[0][i][j] == 0 && i != j) mat[0][i][j] = INF;
		}
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				mat[k][i][j] = min(mat[k - 1][i][j], mat[k - 1][i][k] + mat[k - 1][k][j]);
			}
		}
	}

	int s, e, C;
	while (Q--) {
		cin >> C >> s >> e;
		int ans = mat[C - 1][s][e];
		cout << ((ans == INF) ? -1 : ans) << '\n';
	} 

	return 0;
}