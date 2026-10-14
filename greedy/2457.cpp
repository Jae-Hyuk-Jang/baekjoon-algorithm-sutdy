#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

#define x first
#define y second

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<pii> flower;
	for (int i = 0; i < n; i++) {
		int sm, sd, em, ed; cin >> sm >> sd >> em >> ed;
		flower.push_back({sm * 100 + sd, em * 100 + ed});
	}

	int t = 301;
	int ans = 0;
	while (t < 1201) {
		int nxt_t = t;
		for (int i = 0; i < n; i++) {
			if (flower[i].x <= t && flower[i].y > nxt_t) nxt_t = flower[i].y;
		}

		if (nxt_t == t) {
			cout << 0;
			return 0;
		}
		ans++;
		t = nxt_t;
	}
	cout << ans;
	return 0;
}