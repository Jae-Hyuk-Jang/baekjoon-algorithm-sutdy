#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	unsigned long long cnt = 0;

	int N, h; cin >> N;
	stack<int> st;
	for (int i = 0; i < N; i++) {
		cin >> h;

		while (!st.empty() && st.top() <= h) st.pop();
		cnt += st.size();
		st.push(h);
	}
	cout << cnt;
	return 0;
}