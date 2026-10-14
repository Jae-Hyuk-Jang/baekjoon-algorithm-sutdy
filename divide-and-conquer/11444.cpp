#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
using ll = long long;

map<ll, ll> m;

ll fib(ll x) {
    if(m[x]) return m[x];

    ll result;

    if (x % 2 ==0) result = (fib(x/2)*(fib(x/2+1) + fib(x/2 - 1))) % MOD;
    else result = ((fib((x+1)/2) * fib((x + 1)/2))%MOD) +((fib((x-1)/2)*fib((x-1)/2))%MOD)%MOD;

    return m[x] = result % MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;

    m[0] = 0, m[1] = 1, m[2] = 1;
    cout << fib(n);

    return 0;
}