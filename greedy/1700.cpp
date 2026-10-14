#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int N, K;
int order[101], plugged[101];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < K; i++) cin >> order[i];

	int ret = 0;
	for (int i = 0; i < K; i++) {
		bool flag = false;

		for (int j = 0; j < N; j++) {
			if (plugged[j] == order[i]) flag = true;
		}
		if (flag) continue;

		for (int j = 0; j < N; j++) {
			if (!plugged[j]) {
				plugged[j] = order[i];
				flag = true;
				break;
			}
		}
		if (flag) continue;


		int unplug, idx = 0;
		for (int j = 0; j < N; j++) {
			int count = 101;
			for (int k = i + 1; k < K; k++) {
				if (plugged[j] == order[k]) {
					count = k;
					break;
				}
			}
			if (count > idx) {
				unplug = j;
				idx = count;
			}
		}
		ret++;
		plugged[unplug] = order[i];
	}
	
	cout << ret << '\n';
	return 0;
}