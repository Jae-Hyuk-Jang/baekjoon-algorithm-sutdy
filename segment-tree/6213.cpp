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
    return {min(a.first, b.first), max(a.second, b.second)};
}

pii init(int s, int e, int node) {
    if(s == e)  return tree[node] = {arr[s], arr[s]};
    int mid = (s + e) / 2;
    return tree[node] = combine(init(s, mid, node * 2), init(mid+1, e, node*2 + 1));
}

pii query(int s, int e, int l, int r, int node) {
    if(r < s || e < l) return {INF, -INF};
    if(l <= s && e <= r) return tree[node];
    
    int mid = (s + e) / 2;
    return combine(query(s, mid, l, r, node * 2), query(mid + 1, e, l, r, node * 2 + 1));
}


pii update(int s, int e, int idx, ll orinigal, ll value,  int node) {
    if(idx < s || e < idx) return tree[node];
    if(s == e) {
       return tree[node] = {min(tree[node].first, value), max(tree[node].second, value)};
    }
    int mid = (s + e) / 2;
    return tree[node] = combine(update(s, mid, idx, orinigal,value, node*2), update(mid +1, e, idx, orinigal, value, node*2 + 1));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    for(int i =1; i<= N; i++) cin >> arr[i];
    init(1, N, 1);
    while(Q--) {
        int a, b; cin >>a >> b;
        int mn, mx;
        tie(mn, mx) = query(1, N, a, b, 1);
        cout << mx - mn << '\n';
    }

    return 0;
}

