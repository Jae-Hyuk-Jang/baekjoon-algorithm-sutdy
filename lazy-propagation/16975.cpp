#include<bits/stdc++.h>
#define MX 1000001
using namespace std;
using ll = long long;

ll v[MX], tree[MX * 4];


void init(int start, int end, int node) {
    if(start == end) {
        tree[node] = v[start];
        return;
    }
    int mid = (start + end) / 2;
    tree[node] = 0;
    init(start, mid, node*2);
    init(mid+1, end, node*2+1);
}

void update(int start, int end ,int node, int left, int right, int value) {
    if (end < left || right < start) return;
    if (left <= start && end <= right) {
        tree[node] += value;
        return;
    }
    int mid = (start + end) / 2;
    update(start, mid, node*2, left, right, value);
    update(mid+1, end, node*2 + 1, left, right, value);
}
    
ll query(int start, int end, int node, int idx, ll ans) {
    if(idx < start || end < idx) return 0;
    ans += tree[node];
    if(start == end) return ans;
    int mid = (start + end) / 2;
    return query(start, mid, node*2, idx, ans) +
    query(mid+1, end, node*2 + 1, idx, ans);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i=0; i< n; i++) cin >> v[i];

    init(0, n-1, 1);

    int m; cin >> m;
    for(int i= 0 ;i < m; i++) {
        int a; cin >> a;
        if(a==1) {
            int b, c,d; cin >> b >> c >> d;
            update(0, n-1, 1, b-1, c-1, d);
        }
        else {
            int b; cin >> b;
            cout << query(0, n-1, 1, b-1, 0) << '\n';
        }
    }

    return 0;
}