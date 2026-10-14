#include<bits/stdc++.h>
#define MX 222
using namespace std;
using p = pair<int, int>;

int id[MX][MX];
vector<p> g[20202];
int arr[MX][MX];

int n;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void pre() {
    int cnt = 1;
    for (int i = 1; i <= 125; i++) {
        for (int j = 1; j <= 125; j++) {
            id[i][j] = cnt++;
        }
    }
}

void init() {
    for (int i = 0; i < 20202; i++) g[i].clear();
}

int dijkstra() {
    priority_queue<p> pq;
    pq.push({ 0, 0 });
    vector<int> dist(20202, 1e9+7);
    dist[0] = 0;
    while (!pq.empty()) {
        int now = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (dist[now] < cost) continue;

        for (auto i : g[now]) {
            int nxt = i.first;
            int nxtCost = i.second + cost;
            if (dist[nxt] > nxtCost) {
                pq.push({ -nxtCost, nxt });
                dist[nxt] = nxtCost;
            }
        }
    }
    return dist[id[n][n]];
}

void solve(int tc) {
    init();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    g[0].push_back({ 1, arr[1][1] });
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x < 1 || y < 1 || x > n || y > n) continue;
                g[id[i][j]].push_back({ id[x][y], arr[x][y] });
            }
        }
    }

    cout << "Problem " << tc << ": " << dijkstra() << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    pre();
    int cnt = 1;
    while (1) {
        cin >> n;
        if (n) solve(cnt++);
        else break;
    }

    return 0;
}