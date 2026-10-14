#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k; cin >> n >> k;
	vector<bool> checked(n + 1, true);
	for (int i = 2; i <= n; i++) {
		if (!checked[i])continue;
		for (int j = i; j <= n; j += i) {
			if (!checked[j]) continue;
			checked[j] = false;
			k--;
			if (!k) {
				cout << j;
				return 0;
			}
		}
	}

	return 0;
}