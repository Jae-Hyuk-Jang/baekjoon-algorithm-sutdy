#include<bits/stdc++.h>
using namespace std;

int t, n, m;
int coin[22];
int dp[22][10002];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> coin[i];
			dp[i][0] = 1;
		}
		cin >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= m; j++) {
				dp[i][j] = 0;
				if (i - 1 >= 0) dp[i][j] += dp[i - 1][j];
				if (j - coin[i] >= 0) dp[i][j] += dp[i][j - coin[i]];
			}
		}
		cout << dp[n - 1][m] << '\n';
	}

	return 0;
}