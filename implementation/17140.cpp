#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

#define MX 105
#define X first
#define Y second

int mat[MX][MX];
int n = 3, m = 3;
int r, c, k;

void transpose() {
	int mx = max(n, m);
	for (int i = 1; i <= mx; i++) {
		for (int j = i + 1; j <= mx; j++) {
			swap(mat[j][i], mat[i][j]);
		}
	}
	swap(n, m);
}

void freq_sort(int arr[]) {
	vector<pii> v;
	int freq[101] = {};
	for (int j = 1; j <= m; j++) freq[arr[j]]++;
	for (int i = 1; i <= 100; i++) {
		if (!freq[i]) continue;
		v.push_back({ freq[i], i });
	}
	sort(v.begin(), v.end());
	int j = 0;
	for (const auto& p : v) {
		if (j == 100) break;
		arr[++j] = p.Y;
		arr[++j] = p.X;
	}
	m = max(m, j);
	fill(arr + j + 1, arr + m + 1, 0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> mat[i][j];
		}
	}

	int ans = 0;
	while (mat[r][c] != k && ans <= 100) {
		bool transposed = false;
		if (n < m) {
			transpose();
			transposed = true;
		}
		for (int i = 1; i <= n; i++) freq_sort(mat[i]);
		if (transposed) transpose();
		ans++;
	}
	cout << (ans > 100 ? -1 : ans);

	return 0;
}