#include<bits/stdc++.h>
#include<unordered_map>
#define MX 100005
using namespace std;

unordered_map<string, int> s_to_i;
string i_to_s[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> i_to_s[i];
		s_to_i[i_to_s[i]] = i;
	}

	while (m--) {
		string q; cin >> q;
		if (isdigit(q[0])) cout << i_to_s[stoi(q)];
		else cout << s_to_i[q];
		cout << '\n';
	}

	return 0;
}