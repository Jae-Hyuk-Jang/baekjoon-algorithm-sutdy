#include <bits/stdc++.h>
using namespace std;

static int cnt[1000001];

struct Query {
    int l, r, idx, block;
    bool operator<(const Query& other) const {
        if(block != other.block) return block < other.block;
        if (block & 1) return r > other.r;
        return r < other.r;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, Q; cin >> N;
    vector<int> a(N +1);
    for (int i = 1; i<= N; i++) cin >> a[i];

    cin >> Q;
    vector<Query> qs(Q);
    int B= max(1, (int)sqrt(N));

    for (int i= 0; i < Q; i++) {
        int L, R; cin >> L >> R;
        qs[i] = { L, R, i , L / B };
    }
    sort(qs.begin(), qs.end());
    
    vector<int> ans(Q);
    long long answer= 0;
    auto add = [&](int x) {
        int before = cnt[x]++;
        if (before == 0) answer++;
        else if (before == 1) answer--;
    };

    auto remove = [&](int x) {
        int before = cnt[x]--;
        if (before == 1) answer--;
        else if (before == 2) answer++;
    };

    int curL = 1, curR = 0;
    for (auto &q : qs) {
        while(curL > q.l) add(a[--curL]);
        while (curR < q.r) add(a[++curR]);
        while (curL < q.l) remove(a[curL++]);
        while(curR > q.r)  remove(a[curR--]);
        ans[q.idx] = (int) answer;
    }

    for(int i = 0; i< Q; i++) cout << ans[i] << '\n';
    
    return 0;
}