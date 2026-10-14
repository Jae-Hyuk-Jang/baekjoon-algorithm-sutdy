#include<bits/stdc++.h>
#define MX 210
#define INF 1e9
using namespace std;

int n, m;
int mat[MX][MX];
tuple<int, int, int> edges[20005];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		fill(mat[i], mat[i] + n + 1, INF);
		mat[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		int a, b, l; cin >> a >> b >> l;
		mat[a][b] = min(mat[a][b], l);
		mat[b][a] = min(mat[b][a], l);
		edges[i] = { a, b, l };
	}


	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
			}
		}
	}

	double ans = INF;
	for (int i = 1; i <= n; i++) {
		double totalTime = 0;
		for (int j = 0; j < m; j++) {
			int s, e, l;
			tie(s, e, l) = edges[j];
			totalTime = max(totalTime, (double)(l + mat[i][s] + mat[i][e]) / 2);
		}
		ans = min(ans, totalTime);
	}

	cout << fixed;
	cout.precision(1);
	cout << ans;

	return 0;
}