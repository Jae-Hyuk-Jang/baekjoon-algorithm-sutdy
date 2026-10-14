#include<bits/stdc++.h>
#define MX 50001
using namespace std;

int dp[MX];
int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	cout << dp[n];

	return 0;
}