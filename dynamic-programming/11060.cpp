#include<bits/stdc++.h>
#define MX 1001
#define INF 1e9
using namespace std;

int n;
int arr[MX];
int dp[MX];

int dfs(int cur) {
	if (cur >= n) return INF;
	if (cur == n - 1) return 0;
	if (dp[cur] != -1) return dp[cur];
	dp[cur] = INF;

	for (int i = 1; i <= arr[cur]; i++) {
		dp[cur] = min(dp[cur], dfs(cur + i) + 1);
	}
	return dp[cur];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	fill(dp, dp + n + 1, -1);

	int answer = dfs(0);
	cout << ((answer == INF) ? -1 : answer);

	return 0;
}