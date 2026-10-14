#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    int n; cin >> n;
    int ans = n/5;
    int change = n%5;

    if(n < 5) {
        if(n%2==0) cout << n/ 2;
        else cout << -1;
    }
    else if(change % 2 != 0) {
       change += 5;
       ans--;
       ans += change/2;
       cout << ans;
    } else {
        ans += change/2;
        cout << ans;
    }

    return 0;
}