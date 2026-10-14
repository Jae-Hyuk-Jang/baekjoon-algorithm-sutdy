#include<bits/stdc++.h>
using namespace std;

const int MX = 1e6 + 2;

int dp[MX];
int cnt, num;
int lis;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> num;
		dp[num] = dp[num - 1] + 1;
		lis = max(lis, dp[num]);
	}
	cout << cnt - lis;

	return 0;
}