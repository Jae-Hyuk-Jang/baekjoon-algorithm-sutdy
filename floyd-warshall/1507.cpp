#include<bits/stdc++.h>
#define MX 22
using namespace std;

int mat[MX][MX], u[MX][MX];
int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mat[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			bool isunit = true;

			for (int k = 1; k <= n; k++) {
				if (k == i || k == j) continue;
				int tmp = mat[i][k] + mat[k][j];
				if (mat[i][j] > tmp) {
					cout << -1;
					return 0;
				}
				else if (tmp == mat[i][j]) isunit = false;
			}
			if (isunit) u[i][j] = u[j][i] = 1;
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if(u[i][j]) ans += mat[i][j];
		}
	}
	cout << ans;

	return 0;
}