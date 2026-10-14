#include<bits/stdc++.h>
#define MX 1001
using namespace std;

int n, m;
int dp[MX][MX];

int dx[] = { 0, 1, 1 };
int dy[] = { 1, 0, 1 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			dp[i][j] = s[j] - '0';
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (dp[i][j] == 0) continue;
			dp[i][j] = min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] }) + 1;
		}
	}

	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			answer = max(answer, dp[i][j]);
		}
	}
	cout << answer * answer;

	return 0;
}