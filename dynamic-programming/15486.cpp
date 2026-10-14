#include<bits/stdc++.h>
#define MX 1500001
#define INF 1e9
using namespace std;

int N;
int times[MX], price[MX];
int dp[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> times[i] >> price[i];
	}


	for (int i = 1; i <= N; i++) {
		if (dp[i] < dp[i - 1]) dp[i] = dp[i - 1];
		dp[i + times[i] - 1] = max(dp[i - 1] + price[i], dp[i + times[i] - 1]);
	}
	cout << dp[N];
	return 0;
}