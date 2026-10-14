#include<bits/stdc++.h>
#define MX 1000001
#define INF 1e10
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N, Q;
ll arr[MX];
pii tree[MX * 4];

pii combine(pii a, pii b) {
    if(a.first < b.first) return a;
    else if(a.first > b.first) return b;
    else return ((a.second < b.second) ? a : b);
}

pii init(int s, int e, int node) {
    if(s == e) return tree[node] = {arr[s], s};
    int mid = (s + e) / 2;
    return tree[node] = combine(init(s, mid, node * 2), init(mid+1, e, node*2 + 1));
}

pii query(int s, int e, int l, int r, int node) {
    if(r < s || e < l) return {INF, INF};
    if(l <= s && e <= r) return tree[node];
    
    int mid = (s + e) / 2;
    return combine(query(s, mid, l, r, node * 2), query(mid + 1, e, l, r, node * 2 + 1));
}


pii update(int s, int e, int idx, ll value,  int node) {
    if(idx < s || e < idx) return tree[node];
    if(s == e) {
        tree[node].first += value;
        return tree[node];
    }
    int mid = (s + e) / 2;
    return tree[node] = combine(update(s, mid, idx, value, node*2), update(mid +1, e, idx, value, node*2 + 1));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    init(1, N, 1);

    cin >> Q;
    while(Q--) {
        ll type; cin >> type;
        if(type == 1) {
            ll a, b; cin >> a >> b;
            int diff = b - arr[a];
            arr[a] = b;
            update(1, N, a, diff, 1);
        } else {
            cout << tree[1].second << '\n';
        }
    }

    return 0;
}

