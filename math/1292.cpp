#include<bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a, b; cin >> a >> b;
	auto calc = [](int x) {
		int i = 1, sum = 0;
		while (x > i) {
			sum += (i * i);
			x -= (i++);
		}
		return sum + i * x;
	};

	cout << calc(b) - calc(a - 1);

	return 0;
}