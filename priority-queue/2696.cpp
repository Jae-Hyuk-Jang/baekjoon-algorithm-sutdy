#include<bits/stdc++.h>
using namespace std;


void solve() {
	int M = 0, middle, a;
	priority_queue<int, vector<int>, greater<int>> minq;
	priority_queue<int> maxq;
	vector<int> ans;

	cin >> M >> middle;
	ans.push_back(middle);

	for (int i = 2; i <= M; i++) {
		cin >> a;
		if (a > middle) minq.push(a);
		else maxq.push(a);

		if (i % 2 == 0) continue;
		else if (minq.size() < maxq.size()) {
			minq.push(middle);
			middle = maxq.top();
			maxq.pop();
			ans.push_back(middle);
		}
		else if (maxq.size() < minq.size()) {
			maxq.push(middle);
			middle = minq.top();
			minq.pop();
			ans.push_back(middle);
		}
		else ans.push_back(middle);
	}

	cout << M / 2 + 1 << '\n';
	for (int i = 0; i < ans.size(); i++) {
		if (i % 10 == 0 && i != 0) cout << '\n';
		cout << ans[i] << ' ';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) {
		solve();
		cout << '\n';
	}


	return 0;
}