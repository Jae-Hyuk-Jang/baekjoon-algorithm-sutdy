#include<bits/stdc++.h>
#define MX 100001
using namespace std;
using ll = long long;

int N, Q;
ll arr[MX];
ll tree[MX * 4];

ll init(int s, int e, int node) {
    if(s == e) return tree[node] = arr[s];
    int mid = (s + e) / 2;
    return tree[node] = init(s, mid, node * 2) 
    + init(mid+1, e, node*2 + 1);
}

ll query(int s, int e, int l, int r, int node) {
    if(r < s || e < l) return 0;
    if(l <= s && e <= r) return tree[node];
    
    int mid = (s + e) / 2;
    return query(s, mid, l, r, node * 2) + 
    query(mid + 1, e, l, r, node * 2 + 1);
}


ll update(int s, int e, int idx, ll value,  int node) {
    if(idx < s || e < idx) return tree[node];
    if(s ==e) return tree[node] = value;
    int mid = (s + e) / 2;
    return tree[node] = update(s, mid, idx, value, node*2) +
    update(mid +1, e, idx, value, node*2 + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    for(int i= 1; i <= N; i++) {
        cin >> arr[i];
    }
    init(1, N, 1);

    while(Q--) {
        ll x, y, a, b; cin >> x >> y >> a >> b;
        if(x > y) swap(x, y);
        cout << query(1, N, x, y, 1) << '\n';
        update(1, N, a, b, 1);
    }

    return 0;
}












