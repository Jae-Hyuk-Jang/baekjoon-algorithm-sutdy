#include<bits/stdc++.h>
using namespace std;

int n, k;
int coins[12];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> coins[i];

	int cnt = 0;
	int idx = n;
	while (k > 0) {
		int tmp = 0;
		if(idx>0) tmp = k / coins[idx];
		k -= tmp * coins[idx];
		cnt += tmp;
		idx--;
	}
	cout << cnt;
	return 0;
}