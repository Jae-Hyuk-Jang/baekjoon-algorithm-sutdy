#include<bits/stdc++.h>
#define MX 100001
using namespace std;

int arr[MX];
int state[MX];
int N;

void run(int x) {
	int cur = x;
	while (1) {
		state[cur] = x;
		cur = arr[cur];
		if (state[cur] == x) {
			while (state[cur] != -1) {
				state[cur] = -1;
				cur = arr[cur];
			}
			return;
		}
		else if (state[cur] != 0) return;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		cin >> N;
		fill(state, state + N + 1, 0);
		for (int i = 1; i <= N; i++) cin >> arr[i];
		for (int i = 1; i <= N; i++) {
			if (!state[i]) run(i);
		}
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			if (state[i] != -1) cnt++;
		}
		cout << cnt << '\n';
	} 

	return 0;
}