#include<bits/stdc++.h>
using namespace std;
#define MX 1000010
#define MOD 1000000009

int n; 
int dp[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	dp[1] = 1, dp[2] = 2, dp[3] = 4;
	for (int i = 4; i <= 1000000; i++) {
		for (int j = 1; j <= 3; j++) {
			dp[i] = (dp[i] + dp[i - j]) % MOD;
		}
	}
	int t; cin >> t;
	while (t--) {
		cin >> n;
		cout << dp[n] << '\n';
	}

	return 0; 
}