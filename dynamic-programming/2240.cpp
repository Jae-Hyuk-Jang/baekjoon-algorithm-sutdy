#include<bits/stdc++.h>
using namespace std;

#define MX 1002

int a[MX];
int dp[MX][32][3];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t, w; cin >> t >> w;
	for (int i = 1; i <= t; i++) cin >> a[i];

	for (int i = 1; i <= t; i++) {
		dp[i][0][1] = dp[i - 1][0][1] + (a[i] == 1 ? 1 : 0);
		for (int j = 1; j <= w; j++) {
			if (i < j) break;
			if (a[i] == 1) {
				dp[i][j][1] = max(dp[i - 1][j - 1][2], dp[i - 1][j][1]) + 1;
				dp[i][j][2] = max(dp[i - 1][j - 1][1], dp[i - 1][j][2]);
			}
			else {
				dp[i][j][1] = max(dp[i - 1][j - 1][2], dp[i - 1][j][1]);
				dp[i][j][2] = max(dp[i - 1][j - 1][1], dp[i - 1][j][2]) + 1;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= w; i++) ans = max({ ans, dp[t][i][1], dp[t][i][2]});
	cout << ans;
	return 0;
}