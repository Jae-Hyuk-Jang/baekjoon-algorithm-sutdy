#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s; cin >> s;
	int size = s.length();
	stack<char> st;
	int sum = 0;
	int mul = 1;
	
	for (int i = 0; i < size; i++) {
		if (s[i] == '(') {
			mul *= 2;
			st.push(s[i]);
		}
		else if (s[i] == '[') {
			mul *= 3;
			st.push(s[i]);
		}
		else if (s[i] == ')') {
			if (st.empty() || st.top() != '(') {
				cout << 0;
				return 0;
			}
			if (s[i - 1] == '(') sum += mul;
			st.pop();
			mul /= 2;
		}
		else {
			if (st.empty() || st.top() != '[') {
				cout << 0;
				return 0;
			}
			if (s[i - 1] == '[') sum += mul;
			st.pop();
			mul /= 3;
		}
	}

	if (st.empty()) cout << sum;
	else cout << 0;

	return 0;
}