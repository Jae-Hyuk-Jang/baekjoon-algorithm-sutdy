#include<bits/stdc++.h>
#define MX 100001
using namespace std;

int dp[MX][2];
int arr[MX][2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc; cin >> tc;
	while (tc--) {
		int N; cin >> N;
		for (int j = 0; j < 2; j++) {
			for  (int i = 0; i < N; i++){
				cin >> arr[i][j];
				dp[i][j] = 0;
			}
		}


		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 2; j++) {
				int v = 0;
				if (i > 1) v = max(dp[i - 2][0], dp[i - 2][1]);
				if (i > 0) v = max(v, dp[i - 1][1 - j]);
				dp[i][j] = v + arr[i][j];
			}
		}
		cout << max(dp[N - 1][0], dp[N - 1][1]) << '\n';
	}
	

	return 0;
}