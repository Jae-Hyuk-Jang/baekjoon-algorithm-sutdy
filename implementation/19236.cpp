#include<bits/stdc++.h>
using namespace std;

struct Fish {
    int x, y, dir; bool alive;
};

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
int ans = 0;
int board[4][4];
Fish fishes[17];

void dfs(int b[4][4], Fish f[17], int sx, int sy, int sdir, int eatSum) {
    ans = max(ans, eatSum);

    for(int id =1; id <= 16; id++) {
        if(!f[id].alive) continue;
        int x = f[id].x, y = f[id].y, dir = f[id].dir;

        for (int r=0; r < 8; r++) {
            int nd = (dir + r) % 8;
            int nx = x + dx[nd];
            int ny = y + dy[nd];

            if(nx < 0 || nx >= 4|| ny < 0|| ny >= 4) continue;
            if (nx == sx && ny == sy) continue;

            if(b[nx][ny] == 0) {
                b[x][y] = 0;
                b[nx][ny] = id;
                f[id].x = nx; f[id].y =ny; f[id].dir = nd;
            } else {
                int other = b[nx][ny];
                swap(f[id].x, f[other].x);
                swap(f[id].y, f[other].y);
                b[x][y] = other;
                b[nx][ny] = id;
                f[id].dir = nd;
            }
            break;
        }
    }

    for(int step = 1; step <= 3; step++) {
        int nx = sx + dx[sdir] * step;
        int ny = sy + dy[sdir] * step;

        if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) break;
        if (b[nx][ny] == 0) continue;

        int nb[4][4];
        Fish nf[17];
        memcpy(nb, b, sizeof(nb));
        memcpy(nf, f, sizeof(nf));

        int fid = nb[nx][ny];
        int ndir = nf[fid].dir;

        nb[sx][sy] = 0;
        nb[nx][ny] = -1;
        nf[fid].alive = false;

        dfs(nb, nf, nx, ny, ndir, eatSum + fid);
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i< 4; i++) {
        for (int j = 0; j< 4; j++) {
            int a, b; cin >> a >> b;
            board[i][j] = a;
            fishes[a] = { i, j, b -1, true };
        }
    }

    int fisrtFish = board[0][0];
    int sdir = fishes[fisrtFish].dir;
    int eatSum = fisrtFish;
    fishes[fisrtFish].alive= false;
    board[0][0] = -1;
    dfs(board, fishes, 0, 0, sdir, eatSum);
    cout << ans;

    return 0;
}