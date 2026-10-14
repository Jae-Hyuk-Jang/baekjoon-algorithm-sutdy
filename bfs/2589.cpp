#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
using namespace std;
using pii = pair<int, int>;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

char mat[51][51];
int dista[51][51];

int h, w;
vector<pii> v;

int bfs(pii start) {
    for (int i =0;i < h; i++) {
        for(int j = 0; j< w; j++) {
            dista[i][j] = -1;
        }
    }

    queue<pii> q;
    q.push(start);
    dista[start.first][start.second] = 0;

    int best = 0;

    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        best = max(best, dista[x][y]);

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            if(mat[nx][ny] == 'W' || dista[nx][ny] != -1) continue;

            dista[nx][ny] = dista[x][y] + 1;
            q.push({nx, ny});
        }
    }
    return best;
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> h >> w;
    for (int i = 0; i< h; i++) {
        string str; cin >> str;
        for(int j = 0; j< w; j++) {
            mat[i][j] = str[j];
            if(mat[i][j] == 'L') v.push_back({i, j});
        }
    }

    int answer = 0;
    for (auto& p: v) {
        answer = max(answer, bfs(p));
    }
    cout << answer << '\n';
    return 0;
}