#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MX 10005

ll pfSum[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m; cin >> n >> m;

	pfSum[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> pfSum[i];
		pfSum[i] += pfSum[i - 1];
	}

	int l = 0, r = 0;
	int ans = 0;

	while (r <= n) {
		ll cSum = pfSum[r] - pfSum[l];
		if (cSum <= m) {
			if (cSum == m) ans++;
			r++;
		}
		else l++;
	}
	cout << ans;
	return 0;
}