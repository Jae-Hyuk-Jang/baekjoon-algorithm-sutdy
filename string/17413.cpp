#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	stack<char> st;
	string str;
	getline(cin, str);

	auto stackprint = [](stack<char>& s) {
		while (!s.empty()) {
			cout << s.top();
			s.pop();
		}
	};

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '<') {
			stackprint(st);
			while (1) {
				cout << str[i];
				if (str[i] == '>') break;
				i++;
			}
		}
		else if (str[i] == ' ') {
			stackprint(st);
			cout << " ";
		}
		else {
			st.push(str[i]);
		}
	}
	stackprint(st);

	return 0;
}