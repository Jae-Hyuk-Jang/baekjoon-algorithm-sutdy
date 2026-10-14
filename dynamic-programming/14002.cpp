#include<bits/stdc++.h>
using namespace std;

#define MX 1010

int n;
int a[MX], dp[MX], pre[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	fill(dp, dp + n, 1);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				pre[i] = j;
			}
		}
	}

	int maxi = 1, maxd = dp[1];
	for (int i = 2; i <= n; i++) {
		if (maxd < dp[i]) {
			maxi = i;
			maxd = dp[i];
		}
	}

	deque<int> ans;
	int cur = maxi;
	while (cur) {
		ans.push_front(a[cur]);
		cur = pre[cur];
	}
	cout << ans.size() << '\n';
	for (const auto& x : ans) cout << x << ' ';
	return 0;
}