#include<bits/stdc++.h>
#define MX 1001
using namespace std;

int N;
int dp[MX];
int p[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> p[i];

	dp[1] = p[1], dp[2] = max(p[1] * 2, p[2]);
	for (int i = 3; i <= N; i++) {
		dp[i] = p[i];
		for (int k = i - 1; k >= i / 2; k--) {
			dp[i] = max(dp[i], dp[i - k] + dp[k]);
		}
	}
	cout << dp[N];

	return 0;
}