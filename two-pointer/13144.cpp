#include<bits/stdc++.h>
using namespace std;

const int MX = 100002;
int arr[MX];
bool processed[MX];
long long ans = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	processed[arr[0]] = 1;
	int en = 0;
	for (int st = 0; st < n; st++) {
		while (en < n - 1 && !processed[arr[en + 1]]) {
			en++;
			processed[arr[en]] = 1;
		}
		ans += (en - st + 1);
		processed[arr[st]] = 0;
	}
	cout << ans;

	return 0; 
}