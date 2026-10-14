#include<bits/stdc++.h>
#define INF 1e9
#define MX 1001
using namespace std;

int N; 
int dp[MX];
int cost[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> cost[i];

	dp[1] = cost[1];
	dp[2] = min(cost[2], cost[1] * 2);

	for (int i = 3; i <= N; i++) {
		dp[i] = INF;
		for (int j = 0; j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j] + cost[j]);
		}
	}

	cout << dp[N];

	return 0;
}