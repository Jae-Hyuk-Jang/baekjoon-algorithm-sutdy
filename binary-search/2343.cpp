#include<iostream>
#include<algorithm>
#define MX 100004

using namespace std;
using ll = long long;

ll n, m, lo, hi, ret, a[MX], sum, mx;

bool check(int mid) {
    if(mx > mid) return false;
    int temp = mid;
    int cnt = 0;
    for(int i=0; i < n; i++) {
        if(mid - a[i] < 0) mid = temp, cnt++;
        mid -= a[i];
    }
    if(mid != temp) cnt++;
    return cnt <= m;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i< n; i++) cin >> a[i], sum+= a[i], mx = max(mx, a[i]);
    lo = 0, hi = sum;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        if(check(mid)) {
            hi = mid - 1;
            ret = mid;
        } else lo = mid + 1;
    }
    cout << ret;
    return 0;
}