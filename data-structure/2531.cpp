#include<bits/stdc++.h>
using namespace std;

int n, d, k, c;
#define MX 30001

int arr[MX];
int exist[3001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	int l = 0, r = k + l - 1;
	int cnt = 0;
	for (int i = l; i <= r; i++) {
		if (exist[arr[i]] == 0) cnt++;
		exist[arr[i]]++;
	}
	//cout << cnt << '\n';

	int ans = cnt;
	if (exist[c] == 0) ans++;

	while (l < n) {
		l++;
		r++;
		//cout << l << ' ' << r << endl;
		if (--exist[arr[l - 1]] == 0) {
			cnt--;
			//cout << "here1" << endl;
		}
		if (r >= n) r -= n;
		if (++exist[arr[r]] == 1) {
			cnt++;
			//cout << "here2" << endl;
		}

		//cout << cnt << '\n';

		int temp = cnt;
		if (exist[c] == 0) temp++;
		ans = max(ans, temp);
	}
	cout << ans;


	return 0;
}