#include<bits/stdc++.h>
#define MOD 1000
using namespace std;
using ll = long long;

ll n, b;
ll a[5][5];
ll tmp[5][5];
ll ans[5][5];

void matrix(ll x[5][5], ll y[5][5]) {
    for(int i = 0; i< n; i++) {
        for(int j = 0; j< n; j++) {
            tmp[i][j] = 0;
            for(int k = 0; k < n; k++) {
                tmp[i][j] += (x[i][k] * y[k][j]);
            }
            tmp[i][j] %= MOD;
        }
    }

    for(int i=0; i <n; i++) {
        for (int j = 0; j < n; j++) {
            x[i][j] = tmp[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> b;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j< n; j++) {
            cin >> a[i][j];
        }
        ans[i][i] = 1;
    }

    while(b > 0) {
        if(b % 2== 1) matrix(ans, a);
        matrix(a, a);
        b /= 2;
    } 

    for(int i =0; i < n; i++) {
        for(int j = 0; j< n ; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}