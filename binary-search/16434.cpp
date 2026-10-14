#include<iostream>
#include<algorithm>
#define MX 130005

using namespace std;
using ll = long long;

ll n, attack;
ll a[MX], t[MX], h[MX];
ll lo, hi, ret;

bool check(ll mid) {
    ll mxHP = mid;
    ll init_attack = attack;
    for (int i = 0; i < n; i++) {
        if(t[i] == 2) {
            mid = min(mxHP, mid + h[i]);
            init_attack += a[i];
        } else {
            ll cnt = h[i] / init_attack + (h[i] % init_attack ? 1 : 0);
            mid -= (cnt - 1) * a[i];
        }
        if(mid <= 0) return false;
    }
    return true;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> attack;
    for(int i = 0; i < n; i++) cin >> t[i] >> a[i] >> h[i];
    lo = 1, hi = 1e18 + 4;
    while(lo <= hi) {
        ll mid = (lo + hi) >> 1;
        if(check(mid)) hi = mid - 1, ret = mid;
        else lo = mid + 1;
    }
    cout << ret;
    return 0;
}