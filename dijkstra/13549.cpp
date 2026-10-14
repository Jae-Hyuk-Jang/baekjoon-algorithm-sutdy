#include<bits/stdc++.h>
using namespace std;

bool processed[100005];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

	cin >> n >> k;

	q.push({0, n});

	while (!q.empty()) {
		int x = q.top().second;
		int num = q.top().first;
		q.pop();

		processed[x] = 1;

		if (x == k) {
			cout << num << '\n';
			return 0;
		}

		if (x - 1 >= 0 && !processed[x - 1]) q.push({ num + 1, x - 1});
		if (x + 1 <= 100000 && !processed[x + 1]) q.push({ num + 1, x + 1});
		if (x * 2 <= 100000 && !processed[x * 2]) q.push({ num, x * 2 });
	}

	return 0;
}