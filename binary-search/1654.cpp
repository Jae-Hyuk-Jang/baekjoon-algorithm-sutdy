#include<bits/stdc++.h>
using namespace std;

const int MX = 10005;

typedef long long ll;
int k, n;
int arr[MX];

bool solve(ll x) {
	ll cur = 0;
	for (int i = 0; i < k; i++) cur += arr[i] / x;
	return cur >= n;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> n;
	for (int i = 0; i < k; i++) cin >> arr[i];
	ll st = 1, en = 0x7fffffff;
	while (st < en) {
		ll mid = (st + en + 1) / 2;
		if (solve(mid)) st = mid;
		else en = mid - 1;
	}
	cout << st;
	return 0;
}