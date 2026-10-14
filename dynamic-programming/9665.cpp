#include<bits/stdc++.h>
#define MX 10000
using namespace std;

int n, m;
map<char, int> gene;
int price[4];
string a, b;
int dp[MX + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;
	n = a.length();
	m = b.length();
	for (int i = 0; i < 4; i++) {
		int c; cin >> c;
		price[i] = c;
	}
	gene['A'] = price[0];
	gene['C'] = price[1];
	gene['G'] = price[2]; 
	gene['T'] = price[3];

	int total = 0;
	for (int i = 0; i < m; i++) {
		total += gene[b[i]];
	}

	int answer = total;
	for (int st = 1; st <= n; st++) {
		int idx = st;
		int b_idx = 0;
		while (idx < n && b_idx < m) {
			if (a[idx] == b[b_idx]) {
				dp[st] += gene[a[idx]];
				idx++;
			}
			b_idx++;
		}
		answer = min(answer, total - dp[st]);
	}

	cout << answer;
	
	return 0;
}

