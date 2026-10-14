#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int r,c, k;
char mat[6][6];
bool processed[6][6];
int sx, sy, ex, ey;
int cnt = 0;

int dx[] = { -1, 1, 0, 0 };
int dy[] = {0, 0, -1, 1};

void dfs(int cx, int cy, int ex, int ey, int step) {
    if(cx == ex && cy == ey) {
        if(step == k) cnt++;
        return;
    }

    for(int i = 0; i < 4; i++) {
        int nx = cx + dx[i];
        int ny = cy + dy[i];

        if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
        if(processed[nx][ny] || mat[nx][ny] == 'T') continue;
        processed[nx][ny] = true;
        dfs(nx, ny, ex, ey, step+1);
        processed[nx][ny] = false;
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> k;
    for(int i=0; i< r; i++) {
        string s; cin >> s;
        for (int j = 0; j< c; j++) {
            mat[i][j] = s[j];
        }
    }
    sx = r - 1, sy = 0, ex = 0, ey = c - 1;

    processed[sx][sy] = true;
    dfs(sx, sy, ex, ey, 1);

    cout << cnt << '\n';


    return 0;
}