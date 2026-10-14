#include<bits/stdc++.h>
#define MX 50
using namespace std;

int N, M;
int dp[MX];
int vip[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	vip[0] = 0;
	for (int i = 1; i <= M; i++) cin >> vip[i];
	vip[M + 1] = N + 1;

	dp[0] = 1, dp[1] = 1, dp[2] = 2;
	for (int i = 3; i <= N; i++) dp[i] = dp[i - 1] + dp[i - 2];

	int answer = 1;
	for (int i = 1; i <= M + 1; i++) {
		answer *= dp[vip[i] - vip[i-1] - 1];
	}
	cout << answer;

	return 0;
}