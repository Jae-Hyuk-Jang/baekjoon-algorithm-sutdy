#include<bits/stdc++.h>
#define MX 1000010
using namespace std;

int MOD = 1e9;
int n;
int dp[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	dp[0] = 0, dp[1] = 1;
	
	if (n >= 0) {
		for (int i = 2; i <= n; i++) dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	}
	else {
		n = abs(n);
		for (int i = 2; i <= n; i++) dp[i] = (dp[i - 2] - dp[i - 1]) % MOD;
	}
	if (dp[n] > 0) cout << 1;
	else if (dp[n] < 0) cout << -1;
	else cout << 0;
	cout << '\n' << abs(dp[n]);

	return 0;
}