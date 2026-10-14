#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	stack<int> st;
	queue<char> q;
	int cur = 1;
	bool check = true;
	while (n--) {
		int wanted; cin >> wanted;

		if (cur > wanted) {
			if (!st.empty() && wanted == st.top()) {
				q.push('-');
				st.pop();
			}
			else check = false;
		}

		while (cur <= wanted) {
			st.push(cur++);
			q.push('+');
			if (st.top() == wanted && !st.empty()) {
				q.push('-');
				st.pop();
			}
		}
	}

	if (!check) cout << "NO" << '\n';
	else {
		while (!q.empty()) {
			cout << q.front() << '\n';
			q.pop();
		}
	}

	return 0;
}