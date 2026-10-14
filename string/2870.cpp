#include<bits/stdc++.h>
using namespace std;

vector<string> ans;
string str;


bool cmp(string& a, string& b) {
	if (a.length() == b.length()) return a < b;
	return a.length() < b.length();
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	while (n--) {
		cin >> str;
		int pos = 0, nxt_pos = 0;
		while (1) {
			while (str[nxt_pos] >= 'a' && str[nxt_pos] <= 'z') {
				nxt_pos++;
			}

			pos = nxt_pos;
			if (pos >= str.length()) break;
			while (str[nxt_pos] >= '0' && str[nxt_pos] <= '9') {
				nxt_pos++;
			}

			ans.push_back(str.substr(pos, nxt_pos - pos));
			pos = nxt_pos;
		}
	}

	for (auto& s : ans) {
		int pos = 0;
		while (s[pos] == '0') pos++;
		string ss = s.substr(pos, s.length() - pos);
		if (ss == "") ss = "0";
		s = ss;
	}

	sort(ans.begin(), ans.end(), cmp);
	for (const auto& s : ans) cout << s << '\n';

	return 0;
}