#include<iostream>
#include<algorithm>
#include<climits>
#include<string>

using namespace std;

int n; 
int a[44];
int ret = INT_MAX;
string s;

void go(int here) {
    if(here == n + 1) {
        int sum = 0;
        for (int i = 1; i < (1<<n); i *=2) {
            int cnt = 0;
            for(int j = 1; j <= n; j++) if(a[j] & i)cnt++;
            sum += min(cnt, n - cnt);
        }
        ret = min(ret, sum);
        return;
    }

    go(here + 1);
    a[here] = ~a[here];
    go(here + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> s;
        int value = 1;
        for(int j = 0; j < s.size(); j++) {
            if(s[j] == 'T') a[i] |= value;
            value *= 2;
        }
    }

    go(1);
    cout << ret << '\n';

    return 0;
}