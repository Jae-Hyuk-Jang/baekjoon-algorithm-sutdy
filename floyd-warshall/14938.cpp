#include<bits/stdc++.h>
#define MX 110
#define INF 1e9
using namespace std;

int n, m, r;
int item[MX];
int a, b, l;
int mat[MX][MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> r;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == j)mat[i][j] = 0;
			else mat[i][j] = INF;
		}
	}

	for (int i = 1; i <= n; i++) cin >> item[i];
	for (int i = 0; i < r; i++) {
		cin >> a >> b >> l;
		mat[a][b] = l;
		mat[b][a] = l;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
			}
		}
	}

	/*for (int i = 1; i <= n; i++) {
	
		for (int j = 1; j <= n; j++) {
			cout << mat[i][j] << ' ';
		}
		cout << endl;
	
	}*/

	int answer = 0;

	for (int i = 1; i <= n; i++) {
		int temp = 0;
		for (int j = 1; j <= n; j++) {
			if (mat[i][j] <= m) {
				temp += item[j];
			}
		}
		answer = max(answer, temp);
	}
	cout << answer;
	return 0;
}