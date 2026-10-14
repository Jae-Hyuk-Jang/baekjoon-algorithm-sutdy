#include<iostream>
#include<algorithm>
#define MX 60000000000LL

using namespace std;
using ll = long long;

ll n, m;
ll a[10004];

bool check(ll t) {
    ll cnt = m; 
    for(int i = 0; i < m; i++) cnt += (t / a[i]);
    return cnt >= n;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i< m; i++) cin >> a[i];
    if(n <= m) {cout << n; return 0;}

    ll lo = 0, hi = MX, ret = hi;
    while(lo <= hi) {
        ll mid = (lo + hi) >> 1;
        if(check(mid)) ret = mid, hi = mid -1;
        else lo = mid + 1;
    }

    ll cnt = m;
    for(int i =0; i< m; i++) cnt += (ret - 1) / a[i];
    for(int i = 0; i< m; i++) {
        if(ret % a[i] == 0) {
            cnt++;
            if(cnt == n) {
                cout << i + 1;
                return 0;
            }
        }
    }

    return 0;
}