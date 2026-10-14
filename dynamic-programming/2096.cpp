#include<bits/stdc++.h>
using namespace std;

int n, t0, t2;
int mx[3], mn[3], in[3];
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < 3; i++) {
        cin >> mx[i];
        mn[i] = mx[i];
    }
    
    for (int i = 1; i < n; i++) {
        for(int j = 0; j< 3; j++) cin >> in[j];
        t0 = mx[0], t2 = mx[2];
        
        mx[0] = max(mx[0], mx[1]) + in[0];
        mx[2] = max(mx[1], mx[2]) + in[2];
        mx[1] = max(max(t0, mx[1]), t2) + in[1];
        
        t0 = mn[0], t2 = mn[2];
        
        mn[0] = min(mn[0], mn[1]) + in[0];
        mn[2] = min(mn[1], mn[2]) + in[2];
        mn[1] = min(min(t0, mn[1]), t2) + in[1];
    }
    cout << max({mx[0], mx[1], mx[2]}) << ' ' << min({mn[0], mn[1], mn[2]});
    return 0;
}