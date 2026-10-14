#include<bits/stdc++.h>
using namespace std;

using ll = long long;
ll n, p, q;
map<ll, ll> a;

ll go(ll x) {
	if (a[x] != 0) return a[x];
	if (x == 0) return a[x] = 1;
	return a[x] = go(x / p) + go(x / q);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> p >> q;
	cout << go(n);

	return 0;
}