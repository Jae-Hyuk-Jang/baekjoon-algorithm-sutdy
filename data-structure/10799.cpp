#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
stack<char> st;
ll ans = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	int size = s.length();

	for (int i = 0; i < size; i++) {
		if (s[i] == '(') {
			st.push('(');
		}
		else {
			if (s[i - 1] == '(') {
				st.pop();
				ans += st.size();
			}
			else {
				st.pop();
				ans++;
			}
		}
	}

	cout << ans;

	return 0;
}