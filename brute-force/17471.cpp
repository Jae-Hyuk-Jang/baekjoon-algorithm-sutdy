#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<climits>

using namespace std;
using pii = pair<int, int>;

int n, a[11], m, temp, ret = INT_MAX, comp[11], visited[11];

vector<int> adj[11];

pii dfs(int here, int value) {
    visited[here] = 1;
    pii ret = {1, a[here]};
    for(int there : adj[here]) {
        if(comp[there] != value) continue;
        if(visited[there]) continue;
        pii _temp = dfs(there, value);
        ret.first += _temp.first;
        ret.second += _temp.second;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <=n ; i++) {
        cin >> m;
        for(int j = 0; j < m; j++) {
            cin >> temp;
            adj[i].push_back(temp);
            adj[temp].push_back(i);
        }
    }


    for (int i = 1; i < (1 << n) - 1; i++) {
        fill(comp, comp + 11 , 0);
        fill(visited, visited + 11, 0);
        int idx1 = -1, idx2 = -1;
        for (int j = 0; j < n; j++) {
            if(i & (1 << j)) { comp[j + 1] = 1; idx1 = j + 1; }
            else idx2 = j + 1;
        }
        pii comp1 = dfs(idx1, 1);
        pii comp2 = dfs(idx2, 0);
        if(comp1.first + comp2.first == n) ret = min(ret, abs(comp1.second - comp2.second));
    }
    cout << (ret == INT_MAX ? -1 : ret) << '\n';
    return 0;
}