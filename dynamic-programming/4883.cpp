#include<bits/stdc++.h>
using namespace std;

#define MX 100005

int a[MX][3], dp[MX][3];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int k = 1;
	while (1) {
		int n; cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> a[i][j];
			}
		}

		dp[0][0] = 1001;
		dp[0][1] = a[0][1];
		dp[0][2] = a[0][1] + a[0][2];

		for (int i = 1; i < n; i++) {
			dp[i][0] = a[i][0] + min(dp[i - 1][0], dp[i - 1][1]);
			dp[i][1] = a[i][1] + min({ dp[i - 1][0], dp[i - 1][1], dp[i - 1][2], dp[i][0] });
			dp[i][2] = a[i][2] + min({ dp[i - 1][1], dp[i - 1][2], dp[i][1] });
		}
		cout << k++ << ". " << dp[n - 1][1] << '\n';
	}

	return 0;
}