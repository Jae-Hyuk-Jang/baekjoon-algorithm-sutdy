#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

#define MX 100005

using namespace std;
using ll = long long;

int n, m, x, a, b, visited[MX];
vector<int> h[MX], l[MX];

int bfs(int here, vector<int> adj[]) {
    queue<int> q;
    visited[here] = true;
    q.push(here);

    int ret = 0;
    while(q.size()) {
        int _here = q.front(); q.pop();
        for(int there : adj[_here]) {
            if(visited[there]) continue;
            visited[there] = true;
            q.push(there);
            ret++;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> x;
    for (int i = 0; i< m; i++) {
        cin >> a >> b; h[a].push_back(b); l[b].push_back(a);
    }
    
    int ans1 = bfs(x, l);
    fill(visited, visited + MX, 0);
    int ans2 = bfs(x, h);

    cout << ans1 + 1 << ' ' << n - ans2 << '\n';

    return 0;
}