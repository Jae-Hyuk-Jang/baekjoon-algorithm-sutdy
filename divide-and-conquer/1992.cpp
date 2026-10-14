#include<bits/stdc++.h>
using namespace std;

int mat[65][65];
int n;


void quad(int n, int x, int y) {
	if (n == 1) {
		cout << mat[x][y];
		return;
	}

	bool zero = true, one = true;
	for (int i = x; i < n + x; i++) {
		for (int j = y; j < n + y; j++) {
			if (mat[i][j]) zero = false;
			else one = false;
		}
	}

	if (zero) cout << 0;
	else if (one) cout << 1;
	else {
		cout << "(";
		quad(n / 2, x, y);
		quad(n / 2, x, y + n / 2);
		quad(n / 2, x + n / 2, y);
		quad(n / 2, x + n / 2, y + n / 2);
		cout << ")";
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < n; j++) {
			mat[i][j] = s[j] - '0';
		}
	}
	quad(n, 0, 0);

	return 0;
}