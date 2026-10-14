#include<bits/stdc++.h>
#define MX 10005
using namespace std;

int N, K;
int arr[MX], dp[MX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> arr[i];
	fill(dp, dp + MX, 100005);
	dp[0] = 0;
	for (int i = 0; i < N; i++) {
		for (int j = arr[i]; j <= K; j++) {
			dp[j] = min(dp[j], dp[j - arr[i]] + 1);
		}
	}
	cout << ((dp[K] == 100005) ? -1 : dp[K]);

	return 0;
}