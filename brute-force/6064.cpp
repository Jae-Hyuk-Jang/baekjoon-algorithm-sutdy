#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		int m, n, x, y; cin >> m >> n >> x >> y;
		int mod = gcd(m, n);
		int flag = m * n / mod;

		int answer = -1;
		for (int i = x; i <= flag; i+= m) {
			int ny = i % n;
			if (ny == 0) ny = n;

			if (ny == y) {
				answer = i;
				break;
			}
		}
		cout << answer << '\n';
	}

	return 0;
}