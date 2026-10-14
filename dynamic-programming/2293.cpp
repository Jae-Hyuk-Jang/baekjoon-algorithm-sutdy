#include<bits/stdc++.h>
using namespace std;

const int MX = 10005;
int a[MX], dp[MX];
int n, k;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = a[i]; j <= k; j++) {
			dp[j] += dp[j - a[i]];
		}
	}
	cout << dp[k] << '\n';

	return 0;
}