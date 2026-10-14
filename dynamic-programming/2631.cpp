#include<bits/stdc++.h>
using namespace std;

#define MX 201
int arr[MX];
int dp[MX];
int N;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];

	int lis = 0;
	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		lis = max(lis, dp[i]);
	}
	cout << N - lis;

	return 0;
}