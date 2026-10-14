#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;cin >> n >> k;
	string s; cin >> s;
	stack<char> st,st2;
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		while (!st.empty() && cnt < k && s[i] > st.top()) {
			cnt++;
			st.pop();
		}
		st.push(s[i]);
	}

	while (cnt < k) {
		cnt++; st.pop();
	}

	while (!st.empty()) { st2.push(st.top()); st.pop(); }
	while (!st2.empty()) { cout << st2.top(); st2.pop(); }

	return 0;
}