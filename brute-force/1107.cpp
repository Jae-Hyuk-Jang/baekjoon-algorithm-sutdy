#include<bits/stdc++.h>
using namespace std;

int n, m;
bool isvalid[10];

bool ismove(int num) {
	if (num == 0) {
		if (isvalid[0]) return true;
		return false;
	}

	while (num) {
		if (!isvalid[num % 10]) return false;
		num /= 10;
	}
	return true;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	fill(isvalid, isvalid + 10, true);
	for (int i = 0; i < m; i++) {
		int idx; cin >> idx; 
		isvalid[idx] = false;
	}
	
	int result = abs(n - 100);

	for (int i = 0; i < 1000001; i++) {
		if (ismove(i)) {
			int move = to_string(i).length();
			move += abs(i - n);
			result = min(result, move);
		}
	}

	cout << result;
	return 0;
}