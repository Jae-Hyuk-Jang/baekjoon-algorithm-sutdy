#include<bits/stdc++.h>
#define MX 100001
using namespace std;

int n; 
int arr[MX];
int ans[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		ans[i] = arr[i] * (n - i);
	}
	sort(ans, ans + n);

	cout << ans[n - 1];

	return 0;
}