#include<bits/stdc++.h>
#define MX 200000
using namespace std;

int arr[MX];
int mp[10];
int mn = 0;
int N;

bool overcheck() {
	int cnt = 0;
	for (int i = 1; i < 10; i++) if (mp[i] > 0)cnt++;
	return((cnt > 2) ? true : false);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];

	int l = 0, r = 0;
	while (l < N) {
		while (r < N) {
			mp[arr[r++]]++;
			if (overcheck()) {
				r--;
				mp[arr[r]]--;
				break;
			}
		}
		mn = max(mn, r - l);
		mp[arr[l++]]--;
	}

	cout << mn;

	return 0;
}