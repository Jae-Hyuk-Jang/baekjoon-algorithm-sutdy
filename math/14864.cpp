#include<bits/stdc++.h>
#define MX 100001
using namespace std;
using ll = long long;

int n, m, x, y, visited[MX], v[MX], flag;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        v[x]++, v[y]--;
    }

    for (int i = 1; i <= n; i++) {
        v[i] += i;
        visited[v[i]]++;
    }

    for (int i = 1; i <= n; i++) {
        if(visited[i] >= 2) flag = 1;
    }

    if(flag) cout << -1 << '\n';
    else {
        for (int i =1; i<= n; i++) cout << v[i] << ' ';
    }


    return 0;
}