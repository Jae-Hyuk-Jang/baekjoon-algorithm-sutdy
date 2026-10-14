#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull num;
stack<pair<ull, int>> st;
ull ans = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N; cin >> N;
	while (N--) {
		cin >> num;
		int cnt = 1;
		while (!st.empty() && st.top().first <= num) {
			ans += st.top().second;
			if (st.top().first == num) cnt += st.top().second;
			st.pop();
		}
		if (!st.empty()) ans++; // num 앞에 num보다 큰 사람 수
		st.push({ num, cnt });
	}
	
	cout << ans;

	return 0;
}