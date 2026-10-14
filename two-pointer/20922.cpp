#include<bits/stdc++.h>
using namespace std;

int arr[200005];
int cnt[100005];
int n, k, ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int r = 0;
	++cnt[arr[r]];
	for (int l = 0; l < n; l++) {
		while (r + 1 != n && cnt[arr[r + 1]] < k) {
			++r;
			cnt[arr[r]]++;
		}
		ans = max(ans, r - l + 1);
		cnt[arr[l]]--;
	}
	cout << ans;
	return 0;
}