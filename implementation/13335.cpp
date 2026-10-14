#include<bits/stdc++.h>
#define MX 1010
using namespace std;

int n, w, L, ans;
int bridge[101];
queue<int> trucks;

bool isDone() {
	for (int i = 0; i < w; i++)
		if (bridge[i]) return false;
	return true;
}

void go() {
	for (int i = w - 1; i > 0; i--) 
		bridge[i] = bridge[i - 1];
	bridge[0] = 0;
}

int calculate() {
	int sum = 0;
	for (int i = 0; i < w; i++) sum += bridge[i];
	return sum;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> w >> L;
	for (int i = 0; i < n; i++) {
		int num = 0; cin >> num;
		trucks.push(num);
	}

	do {
		int tmp = calculate();
		if (tmp <= L) {
			tmp -= bridge[w - 1];
			go();
			if (!trucks.empty() && (tmp + trucks.front() <= L)) {
				bridge[0] = trucks.front();
				trucks.pop();
			}
		}
		++ans;
	} while (!isDone());

	cout << ans;
	return 0;
}