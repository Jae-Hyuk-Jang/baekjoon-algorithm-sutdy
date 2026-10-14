#include<bits/stdc++.h>
#define MX 200001
using namespace std;
using ll = long long;

ll arr[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	int n, m, k;
	int ans;
	while (T--) {
		ans = 0;
		cin >> n >> m >> k;
		for (int i = 1; i <= n; i++) cin >> arr[i];
		if (n == m) {
			ll temp = 0;
			for (int i = 1; i <= m; i++) temp += arr[i];
			if (temp < k) ans++;
			for (int i = 2; i <= n - m; i++) {
				temp -= arr[i - 1];
				temp += arr[i + m - 1];
				if (temp < k) ans++;
			}
		}
		else {
			for (int i = n + 1, j = 0; i <= n + m; i++) arr[i] = arr[++j];
			ll temp = 0;
			for (int i = 1; i <= m; i++) temp += arr[i];
			if (temp < k) ans++;
			for (int i = 2; i <= n; i++) {
				temp -= arr[i - 1];
				temp += arr[i + m - 1];
				if (temp < k) ans++;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}