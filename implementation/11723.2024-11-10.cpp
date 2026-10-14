#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t, x, s = 0;
	string a;

	cin >> t;
	while (t--) {
		cin >> a;
		if (a == "all") {
			s = (1 << 20) - 1;
			continue;
		}
		else if (a == "empty") {
			s = 0; 
			continue;
		}

		cin >> x;
		int k = 1 << (--x);
		if (a == "add") s |= k;
		else if (a == "remove") s &= ~k;
		else if (a == "check") cout << ((s & k)>0) << '\n';
		else if (a == "toggle") s ^= k;
	}

	return 0;
}