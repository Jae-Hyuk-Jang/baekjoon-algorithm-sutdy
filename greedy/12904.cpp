#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s1, s2; cin >> s1 >> s2;
	int idx = s2.size() - 1;
	while (s1.size() < s2.size()) {
		if (s2[idx] == 'A') s2.pop_back();
		else {
			s2.pop_back();
			reverse(s2.begin(), s2.end());	
		}
		idx--;
	}

	if (s1 == s2) cout << 1;
	else cout << 0;

	return 0;
}