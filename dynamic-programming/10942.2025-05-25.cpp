#include<bits/stdc++.h>
#define MX 2010
using namespace std;

int n;
int arr[MX], dp[MX][MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 1; i <= n; i++) {
		dp[i][i] = 1;
		if (arr[i - 1] == arr[i]) dp[i - 1][i] = 1;
	}

	for (int step = 2; step < n; step++) {
		for (int i = 1; i <= n - step; i++) {
			int s = i, e = i + step;
			if (arr[s] == arr[e] && dp[s + 1][e - 1]) dp[s][e] = 1;
		}
	}

	int t; cin >> t;
	while (t--) {
		int s, e; cin >> s >> e;
		cout << dp[s][e] << '\n';
	}

	return 0;
}