#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		string a;
		getline(cin, a);
		if (a == ".")break;
		stack<char>s;
		bool isValid = true;
		for (const auto& c : a) {
			if (c == '(' || c == '[') s.push(c);
			else if (c == ')') {
				if (s.empty() || s.top() != '(') {
					isValid = false;
					break;
				}
				s.pop();
			}
			else if (c == ']') {
				if (s.empty() || s.top() != '[') {
					isValid = false;
					break;
				}
				s.pop();
			}
		}

		if (!s.empty()) isValid = false;
		cout << ((isValid) ? "yes" : "no") << '\n';
	}

	return 0;
}