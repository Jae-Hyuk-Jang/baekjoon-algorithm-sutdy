#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	int ans = 0;

	while (n--) {
		string s; cin >> s;
		stack<int> st;
		for (const auto& c : s) {
			if (!st.empty() && st.top() == c) st.pop();
			else st.push(c);
		}
		if (st.empty())ans++;
	}
	cout << ans << '\n';

	return 0;
}