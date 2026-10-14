#include <bits/stdc++.h>
using namespace std;

struct Shark {
    int x, y, dir;
    bool alive = true;
};

struct Smell {
    int owner = 0;
    int remain = 0;
};

int N, M, K;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

Shark sharks[401];
Smell smell[21][21];
int priorityDir[401][4][4];

bool isOnlySharkOneLeft() {
    for (int i = 2; i <= M; i++) {
        if (sharks[i].alive) return false;
    }
    return true;
}

void moveShark(int id) {
    if (!sharks[id].alive) return;
    int x = sharks[id].x, y = sharks[id].y, d = sharks[id].dir;


    for (int k = 0; k < 4; k++) {
        int nd = priorityDir[id][d][k];
        int nx = x + dx[nd], ny = y + dy[nd];
        if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
        if (smell[nx][ny].remain == 0) {
            sharks[id] = { nx, ny, nd, true };
            return;
        }
    }

    for (int k = 0; k < 4; k++) {
        int nd = priorityDir[id][d][k];
        int nx = x + dx[nd], ny = y + dy[nd];
        if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
        if (smell[nx][ny].owner == id) {
            sharks[id] = { nx, ny, nd, true };
            return;
        }
    }
}

void decaySmells() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (smell[i][j].remain > 0 && --smell[i][j].remain == 0) {
                smell[i][j].owner = 0;
            }
        }
    }
}

void spreadSmells() {
    for (int i = 1; i <= M; i++) {
        if (sharks[i].alive) {
            smell[sharks[i].x][sharks[i].y] = { i, K };
        }
    }
}

void resolveConflicts() {
    static int board[21][21];
    memset(board, 0, sizeof(board));

    for (int i = 1; i <= M; i++) {
        if (sharks[i].alive) {
            int x = sharks[i].x, y = sharks[i].y;
            if (board[x][y] == 0) {
                board[x][y] = i;
            } else {
                if (board[x][y] < i) {
                    sharks[i].alive = false;
                } else {
                    sharks[board[x][y]].alive = false;
                    board[x][y] = i;
                }
            }
        }
    }
}

int simulate() {
    for (int t = 1; t <= 1000; t++) {
        for (int i = 1; i <= M; i++) moveShark(i);
        resolveConflicts();
        decaySmells();
        spreadSmells();
        if (isOnlySharkOneLeft()) return t;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int v; cin >> v;
            if (v) {
                sharks[v] = { i, j, 0, true };
                smell[i][j] = { v, K };
            }
        }
    }

    for (int i = 1; i <= M; i++) {
        int d; cin >> d;
        sharks[i].dir = d - 1;
    }

    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                int d; cin >> d;
                priorityDir[i][j][k] = d - 1;
            }
        }
    }

    cout << simulate();
    return 0;
}
