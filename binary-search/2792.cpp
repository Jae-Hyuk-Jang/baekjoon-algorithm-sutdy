#include<iostream>
#include<algorithm>
#define MX 300004

using namespace std;
using ll = long long;

ll n, m, a[MX], ret = 1e9;

bool check(ll mid) {
    ll num = 0;
    for(int i = 0; i < m; i++) {
        num += a[i] / mid;
        if(a[i] % mid) num++;
    }
    return n >= num;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n>> m;
    ll lo = 1, hi = 0, mid;
    for(int i=0; i< m; i++) cin >> a[i], hi = max(hi, a[i]);
    while(lo <= hi) {
        mid = (lo + hi) >> 1;
        if(check(mid)) {
            ret = min(ret, mid);
            hi = mid - 1;
        } else lo = mid + 1;
    }
    cout << ret;


    return 0;
}