#include<bits/stdc++.h>
#define MX 1000001
using namespace std;
using ll = long long;

int N;
int tree[MX * 4];

void update(int s, int e, int node, int idx, int cnt) {
    if(idx < s || e < idx) return;
    tree[node] += cnt;
    if(s == e) return;
    int m = (s + e) / 2;
    update(s, m, node * 2, idx, cnt);
    update(m + 1, e, node * 2 + 1, idx, cnt);
}

void query(int s, int e, int node, int target) {
    if(s == e) {
        cout << s << '\n';
        tree[node]--;
        return;
    }
    int m  = (s + e) / 2;
    if(target <= tree[node * 2]) query(s, m, node * 2, target);
    else query(m + 1, e, node * 2 + 1, target - tree[node * 2]);
    tree[node]--;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int A, B, C;
    for(int i= 0;i < N; i++) {
        cin >> A;
        if(A== 1) {
            cin >> B;
            query(1, MX, 1, B);
        }
        else {
            cin >> B >> C;
            update(1, MX, 1, B, C);
        }
    }

    return 0;
}