#include<bits/stdc++.h>
#define MX 100100
using namespace std;
using ll = long long;

vector<int> tree[MX];
ll dp[MX];
ll weight[MX], n;
bool processed[MX];

void dfs(int cur) {
	if (processed[cur]) return;
	processed[cur] = 1;
	dp[cur] = weight[cur];
	for (const auto& next : tree[cur]) {
		if (processed[next]) continue;
		dfs(next);
		dp[cur] = max(dp[cur] + dp[next], dp[cur]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		cin >> weight[i];
	}
	dfs(0);
	cout << dp[0];

	return 0;
}