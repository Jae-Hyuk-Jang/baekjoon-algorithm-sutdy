#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;
ll arr[100001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	int l = 0, r = 1;
	ll ans = 2e9;
	while (l < n) {
		ll temp = arr[r] - arr[l];
		if (temp < m) {
			r++;
			continue;
		}
		else if (temp == m) {
			ans = m;
			break;
		}
		ans = min(ans, temp);
		l++;
	}
	cout << ans;

	return 0;
}