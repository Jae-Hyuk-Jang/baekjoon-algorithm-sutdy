#include<iostream>
#include<algorithm>

#define MX 2004

using namespace std;

int n, a[MX], dp[MX][MX], t, from, to;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i<= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) dp[i][i] = 1;
    for(int i = 1; i<= n; i++) {
        if(a[i] == a[i+1]) dp[i][i+1] = 1;
    }

    for(int _size =2; _size <= n; _size++) {
        for (int i = 1; i <= n - _size; i++) {
            if(a[i] == a[i+ _size] && dp[i+1][i + _size - 1]) dp[i][i+ _size] = 1;
        }
    }

    cin >> t;
    while (t--)
    {
        cin >> from >> to;
        cout << dp[from][to] << '\n';
    }
    

    return 0;
}