#include<bits/stdc++.h>
#define MXN 4000002
using namespace std;

vector<bool> arr(MXN, true);
vector<int> primes;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 2; i * i < MXN; i++) {
		if (!arr[i]) continue;
		for (int j = i * i; j < MXN; j += i) {
			arr[j] = false;
		}
	}

	for (int i = 2; i < MXN; i++) {
		if (arr[i]) primes.push_back(i);
	}
	//primes.push_back(0);

	int target, s = 0, e = 1, ans = 0, tmpSum = primes[0];
	cin >> target;

	while (1) {
		if (tmpSum == target) ans++;
		if (tmpSum <= target) tmpSum += primes[e++];
		if (target < tmpSum) tmpSum -= primes[s++];
		if (e == int(primes.size())) break;
	}
	cout << ans;

	return 0;
}