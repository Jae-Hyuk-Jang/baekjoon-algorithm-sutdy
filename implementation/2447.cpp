#include<bits/stdc++.h>
#define MX 2400
using namespace std;

bool arr[MX][MX];
int N;

void divide(int x, int y, int n) {
	if (n == 3) {
		for (int i = x; i < x + 3; i++) {
			for (int j = y; j < y + 3; j++) {
				arr[i][j] = 1;
			}
		}
		arr[x + 1][y + 1] = 0;
		return;
	}
	divide(x, y, n / 3);
	divide(x, y + n / 3, n / 3);
	divide(x, y + 2 * (n / 3), n / 3);
	divide(x + n / 3, y, n / 3);
	divide(x + n / 3, y + 2 * (n / 3), n / 3);
	divide(x + 2 * (n / 3), y, n / 3);
	divide(x + 2 * (n / 3), y + n / 3, n / 3);
	divide(x + 2 * (n / 3), y + 2 * (n / 3), n / 3);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	divide(1, 1, N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << ((arr[i][j]) ? '*' : ' ');
		}
		cout << '\n';
	}
	


	return 0;
}