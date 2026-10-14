#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

const int MX = 22;

enum Block {
    EMPTY = 0, BLACK = -1, RAINBOW = -2
};

int N, M;
int board[MX][MX];
bool processed[MX][MX];
int ans = 0;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

struct BlockGroup {
    vector<pii> cells;
    int size = 0;
    int rainbowCount = 0;
    int baseX = -1, baseY = -1;

    bool operator<(const BlockGroup& other) const {
        if (size != other.size) return size < other.size;
        if (rainbowCount != other.rainbowCount) return rainbowCount < other.rainbowCount;
        if (baseX != other.baseX) return baseX < other.baseX;
        return baseY < other.baseY;
    }
};

BlockGroup bfs(int sx, int sy) {
    BlockGroup group;
    int color = board[sx][sy];
    queue<pii> q;
    vector<pii> rainbowCells;

    processed[sx][sy] = true;
    q.push({sx, sy});
    group.cells.push_back({sx, sy});
    group.size = 1;
    group.baseX =sx; 
    group.baseY = sy;

    while(!q.empty()) {
        int x,y; tie(x, y) = q.front(); q.pop();

        for(int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if(nx < 0 || ny < 0 || nx>=N || ny >= N) continue;
            if(processed[nx][ny]) continue;
            if(board[nx][ny] == color || board[nx][ny] == RAINBOW) {
                processed[nx][ny] = true;
                q.push({nx, ny});
                group.cells.push_back({nx, ny});
                group.size++;
                if (board[nx][ny] == RAINBOW) {
                    group.rainbowCount++;
                    rainbowCells.push_back({nx, ny});
                } else {
                    if (nx < group.baseX || (nx == group.baseX && ny < group.baseY)) {
                        group.baseX = nx; group.baseY = ny;
                    }
                }
            }
        }
    }
    for(auto &p : rainbowCells) processed[p.first][p.second] = false;
    return group;
}

void gravity() {
    for(int j =0; j< N; j++) {
        for(int i = N -1; i >= 0; i--) {
            if (board[i][j] >= 0|| board[i][j] == RAINBOW) {
                int x = i;
                while (x +1 < N && board[x+1][j] == EMPTY) {
                    swap(board[x][j], board[x+1][j]);
                    x++;
                }
            }
        }
    }
}

void rotate() {
    int tmp[MX][MX];
    for (int i = 0; i< N; i++) {
        for(int j = 0; j < N; j++) {
            tmp[i][j] = board[j][N -1 -i];
        }
    }
    memcpy(board, tmp, sizeof(board));
}

BlockGroup findLargestGroup() {
    memset(processed, false, sizeof(processed));
    BlockGroup best;

    for (int i = 0; i< N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] <= 0) continue;
            if(!processed[i][j]) {
                BlockGroup g = bfs(i, j);
                if (g.size >= 2 && best < g) best = g;
            }
        }
    }
    return best;
}

void removeGroup(const BlockGroup& g) {
    for(auto &p : g.cells) board[p.first][p.second] = EMPTY;
    ans += g.size * g.size;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i< N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
            if(board[i][j] == 0) board[i][j] = RAINBOW;
        }
    }

    while(1) {
        BlockGroup g = findLargestGroup();
        if(g.size < 2) break;
        removeGroup(g);
        gravity();
        rotate();
        gravity();
    }

    cout << ans << '\n';
    return 0;
}