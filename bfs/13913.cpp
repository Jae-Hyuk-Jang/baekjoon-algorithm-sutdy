#include<bits/stdc++.h>
#define MX 500001
using namespace std;

int pre[MX];
int board[MX];
queue<int> q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k; cin >> n >> k;
	pre[n] = n;
	board[n] = 1;
	q.push(n);

	while (!board[k]) {
		int x = q.front(); q.pop();

		for (const auto nv : { x - 1, x + 1, 2 * x }) {
			if (nv < 0 || nv >= 100001) continue;
			if (board[nv]) continue;
			board[nv] = board[x] + 1;
			pre[nv] = x;
			q.push(nv);
		}
	}

	cout << board[k] - 1 << '\n';
	stack<int> st;
	for (int s = k; s != n; s = pre[s]) st.push(s);
	st.push(n);
	while (!st.empty()) {
		cout << st.top() << ' ';
		st.pop();
	}

	return 0;
}