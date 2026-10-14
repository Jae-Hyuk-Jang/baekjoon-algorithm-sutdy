#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[31];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	dp[0] = 1, dp[1] = 0, dp[2] = 3;

	for (int i = 3; i <= n; i++) {
		if (i & 1) dp[i] = 0; 
		else {
			for (int j = 2; j <= n; j += 2) {
				if (j == 2) dp[i] = dp[i - j] * dp[2];
				else if ((i - j) >= 0) dp[i] += dp[i - j] * 2;
			} 
		}
	}
	cout << dp[n];

	return 0;
}