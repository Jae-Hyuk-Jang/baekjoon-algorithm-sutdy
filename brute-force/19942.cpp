#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<climits>

using namespace std;

int max_n = INT_MAX;
int mp, mf, ms, mv, n;
int mp_sum, mf_sum, ms_sum, mv_sum, mc_sum;
map<int, vector<vector<int>>> m;

struct node{ int p, f, s, v, c; };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    node data[15];
    cin >> n >> mp >> mf >> ms >> mv;
    for(int i = 0; i< n; i++) {
        cin >> data[i].p >> data[i].f >> data[i].s >> data[i].v >> data[i].c;
    }

    for (int i = 1; i < (1<<n); i++) {
        mp_sum = mf_sum = ms_sum = mv_sum = mc_sum = 0;
        vector<int> v;
        for(int j = 0; j < n; j++) {
            if(i & (1<<j)) {
                mp_sum += data[j].p;
                mf_sum += data[j].f;
                ms_sum += data[j].s;
                mv_sum += data[j].v;
                mc_sum += data[j].c;
                v.push_back(j+1);
            }
        }
        if(mp_sum >= mp && mf_sum >= mf && ms_sum >= ms && mv_sum >= mv) {
            if(max_n >= mc_sum) {
                max_n = mc_sum;
                m[mc_sum].push_back(v);
            }
        }
    }

    if(max_n == INT_MAX) { cout << -1 << '\n'; }
    else {
        cout << max_n << '\n';
        sort(m[max_n].begin(), m[max_n].end());
        for(int x: m[max_n][0]) cout << x << ' ';
    }

    return 0;
}