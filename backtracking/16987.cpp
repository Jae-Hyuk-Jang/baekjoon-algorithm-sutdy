#include<bits/stdc++.h>
using namespace std;

int n;
int s[10], w[10];
int mx = 0;
int cnt = 0;

void eggBreak(int a) {
	if(a == n) {
		mx = max(mx, cnt);
		return;
	}

	if (s[a] <= 0 || cnt == n - 1) {
		eggBreak(a + 1);
		return;
	}

	for (int t = 0; t < n; t++) {
		if (t == a || s[t] <= 0) continue; 
		s[a] -= w[t];
		s[t] -= w[a];
		if (s[a] <= 0) cnt++;
		if (s[t] <= 0) cnt++;
		eggBreak(a + 1);
		if (s[a] <= 0) cnt--;
		if (s[t] <= 0) cnt--;
		s[a] += w[t];
		s[t] += w[a];
	} 
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i] >> w[i];

	eggBreak(0);
	cout << mx;

	return 0;
}