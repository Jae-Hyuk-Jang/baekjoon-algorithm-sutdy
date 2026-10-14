#include<bits/stdc++.h>
using namespace std;

struct Position{
    int x, y, value;
    Position() {};
    Position(int x, int y, int value) : x(x), y(y), value(value) {};
};

struct Compare {
    bool operator()(const Position& a, const Position& b) const {
        if (a.value == b.value) {
            if (a.x == b.x) return a.y > b.y;
            return a.x > b.x;
        }
        return a.value > b.value;
    }
};

int N, M , O; 
int curX, curY, curC;
int board[21][21];
int destX[402], destY[402];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool inSpace(int x, int y) {
    return (x >= 0 && y >= 0 && x < N && y < N);
}

int searchCustomer() {
    bool processed[21][21] = { false };
    priority_queue<Position, vector<Position>, Compare> pq;

    pq.push(Position(curX, curY, 0));
    processed[curX][curY] = true;

    while(!pq.empty()) {
        Position cur = pq.top(); pq.pop();
        if(board[cur.x][cur.y] > 1) {
            curC = board[cur.x][cur.y];
            curX = cur.x;
            curY = cur.y;
            board[curX][curY] = 0;
            return cur.value;
        }
        for (int i =0; i< 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(inSpace(nx, ny) && !processed[nx][ny] && board[nx][ny] !=1) {
                processed[nx][ny] = true;
                pq.push(Position(nx, ny, cur.value + 1));
            }
        }
    }
    return -1;
}

int searchGoal() {
    bool processed[21][21] = { false };
    priority_queue<Position, vector<Position>, Compare> pq;
    pq.push(Position(curX, curY, 0));
    processed[curX][curY] =  true;

    int gx = destX[curC];
    int gy = destY[curC];

    while(!pq.empty()) {
        Position cur = pq.top(); pq.pop();
        if (cur.x == gx && cur.y == gy) {
            curX = gx; curY = gy;
            return cur.value;
        }

        for (int i = 0; i< 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(inSpace(nx, ny) && !processed[nx][ny] && board[nx][ny] != 1) {
                processed[nx][ny] = true;
                pq.push(Position(nx, ny, cur.value + 1));
            }
        }
    }
    return -1;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> O;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    cin >> curX >> curY;
    curX--; curY--;

    for (int i = 2; i < M + 2; i++) {
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        sx--; sy--; ex--; ey--;
        board[sx][sy] = i;   // 손님 출발 위치에 ID 표시
        destX[i] = ex;
        destY[i] = ey;
    }

    int count = 0;
    while (count < M) {
        int dist1 = searchCustomer();  
        if (dist1 == -1 || O - dist1 < 0) {
            cout << -1 << "\n";
            return 0;
        }
        int dist2 = searchGoal();     
        if (dist2 == -1 || O - dist1 - dist2 < 0) {
            cout << -1 << "\n";
            return 0;
        }
        O += dist2 - dist1;  
        count++;
    }

    cout << O << "\n";
    return 0;
}