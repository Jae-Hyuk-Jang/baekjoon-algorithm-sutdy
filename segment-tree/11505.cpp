#include<bits/stdc++.h>
#define MOD 1000000007
#define MX 1000001
using namespace std;
typedef long long ll;

int arr[MX];
ll tree[4 * MX];
int N, M, K;


ll init(int node, int start, int end) {
	if (start == end) return tree[node] = arr[start];

	int mid = (start + end) / 2;
	return tree[node] = init(node * 2, start, mid) * init(node * 2 + 1, mid + 1, end) % MOD;
}

ll multiply(int start, int end, int left, int right, int node) {

	if (right < start || left> end) return 1;

	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;

	return multiply(start, mid, left, right, node * 2) * \
		multiply(mid + 1, end, left, right, node * 2 + 1) % MOD;
}

ll modify(int start, int end, int idx, ll delta, int node) {
	if (end < idx || idx < start) return tree[node];
	if (start == end) return tree[node] = delta;

	int mid = (start + end) / 2;
	return tree[node] = modify(start, mid, idx, delta, node * 2) *\
		modify(mid + 1, end, idx, delta, node * 2 + 1) % MOD;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	init(1, 1, N);

	int a, b, c;
	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			modify(1, N, b, c, 1);
			arr[b] = c;
		}
		else if (a == 2) {
			cout << multiply(1, N, b, c, 1) << '\n';
		}
	}

	return 0;
}