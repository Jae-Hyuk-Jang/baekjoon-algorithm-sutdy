#include<bits/stdc++.h>
#define MX 100001
using namespace std;
typedef long long ll;

ll arr[MX];
ll tree[MX * 4];
ll lazy[MX * 4];
int N, M;


void init(int start, int end, int node) {
	if (start == end) {
		tree[node] = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	init(start, mid, node * 2);
	init(mid + 1, end, node * 2 + 1);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void propagation(int start, int end, int node) {
	if (lazy[node] != 0) {
		tree[node] = (end - start + 1) - tree[node];
		if (start != end) {
			lazy[node * 2] = (lazy[node * 2] + 1) % 2;
			lazy[node * 2 + 1] = (lazy[node * 2 + 1] + 1) % 2;
		}
		lazy[node] = 0;
	}
}

ll query(int start, int end, int left, int right, int node) {
	propagation(start, end, node);
	if (right < start || left > end) return 0;
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return query(start, mid, left, right, node * 2) + query(mid + 1, end, left, right, node * 2 + 1);
}

void update(int start, int end, int left, int right, int node) {
	propagation(start, end, node);
	if (right < start || left > end) return;
	if (left <= start && end <= right) {
		tree[node] = (end - start + 1) - tree[node];

		if (start != end) {
			lazy[node * 2] = (lazy[node * 2] + 1) % 2;
			lazy[node * 2 + 1] = (lazy[node * 2 + 1] + 1) % 2;
		}
		return;
	}

	int mid = (start + end) / 2;
	update(start, mid, left, right, node * 2);
	update(mid + 1, end, left, right, node * 2 + 1);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	ll a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		if (a == 0) update(1, N, b, c, 1);
		else if (a == 1) cout << query(1, N, b, c, 1) << '\n';
	}

	return 0;
}