#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m; cin >> n >> m;

	int smin = 1000, omin = 1000;
	for (int i = 0; i < m; i++) {
		int s, o; cin >> s >> o;
		smin = min(smin, s);
		omin = min(omin, o);
	}

	int base = smin * (n / 6);
	int tmp = min((n % 6 == 0) ? base : base + smin, base + (n % 6) * omin);
	cout << min(omin * n, tmp);


	return 0;
}