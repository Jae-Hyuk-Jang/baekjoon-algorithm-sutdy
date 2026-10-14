#include<iostream>

using namespace std;
using ll = long long;

ll n, dp[31][31];

ll go(int whole, int not_whole) {
    if(whole == 0 && not_whole == 0) return 1;
    ll &ret = dp[whole][not_whole];
    if(ret) return ret;
    if(whole > 0) ret += go(whole -1, not_whole + 1);
    if(not_whole > 0) ret += go(whole, not_whole - 1);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(true) {
        cin >> n; if(n==0) break;
        cout << go(n, 0) << '\n';
    }

    return 0;
}