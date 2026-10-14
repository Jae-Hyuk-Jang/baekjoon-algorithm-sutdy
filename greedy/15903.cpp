#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m; cin >> n >> m;
	priority_queue < ll, vector<ll>, greater<ll>> pq;

	while (n--) {
		int x; cin >> x;
		pq.push(x);
	}

	while (m--) {
		ll a = pq.top(); pq.pop();
		ll b = pq.top(); pq.pop();
		pq.push(a + b);
		pq.push(a + b);
	}
	ll ans = 0;
	while (!pq.empty()) {
		ans += pq.top();
		pq.pop();
	}
	cout << ans;
	return 0;
}