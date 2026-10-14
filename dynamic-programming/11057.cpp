#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1003;
const int MOD = 10007;
ll dp[N][10];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 1;
		for (int j = 1; j < 10; j++) {
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
		}
	}
	cout << accumulate(dp[n], dp[n] + 10, 0) % MOD;
	return 0;
}