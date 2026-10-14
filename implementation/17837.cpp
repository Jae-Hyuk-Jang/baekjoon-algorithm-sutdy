#include<bits/stdc++.h>
#define MX 14
#define MK 11
#define WHITE 0
#define RED 1
#define BLUE 2
using namespace std;


typedef struct _TOKEN {
    int x, y, dir;
}toekn_t;


const int dx[] = { 0, 0, 0, -1, 1 };
const int dy[] = { 0, 1, -1, 0, 0 };

int N, K;

int color[MX][MX];
int board[MX][MX][MK];
int length[MX][MX];

toekn_t token[MK];

inline bool checked(int x, int y) {
    return 0 < x && x <= N && 0 < y && y <= N;
}

int findIdx(int x, int y, int target) {
    for(int i =0; i< MK; i++) {
        if(board[x][y][i] == target) return i;
    }
    return -1;
}

void reverseToken(int x, int y, int start) {
    stack<int> s;
    
    int len = length[x][y];
    for(int i = start; i < len; i++) s.push(board[x][y][i]);

    int idx = start;
    while(!s.empty()) {
        int temp = s.top();
        s.pop();
        board[x][y][idx++] = temp;
    }

}


bool moveToekn() {
    for(int k = 1; k <= K; k++) {
        int x = token[k].x;
        
        int y = token[k].y;
        int dir = token[k].dir;

        int nx = x + dx[dir]; int ny = y + dy[dir];
        if(!checked(nx, ny) || color[nx][ny] == BLUE) {
            switch(dir) {
                case 1: dir =2; break;
                case 2: dir = 1; break;
                case 3: dir = 4; break;
                case 4: dir = 3; break;
            }

            token[k].dir = dir;
            nx = x + dx[dir]; ny = y + dy[dir];

            if(!checked(nx, ny) || color[nx][ny] == BLUE) continue;
        }

        int idx = findIdx(x, y, k);
        if (idx == -1) cout << "Index Error\n";

        int fromEnd = length[x][y];
        int toEnd = length[nx][ny];

        for(int i = idx; i < fromEnd; i++) {
            int temp = board[x][y][i];
            board[x][y][i] = 0;
            board[nx][ny][toEnd++] = temp;
            token[temp].x = nx; token[temp].y = ny;
        }

        if(toEnd >= 4) return false;

        length[x][y] = idx;
        length[nx][ny] = toEnd;

        if(color[nx][ny] == RED) {
            reverseToken(nx, ny, toEnd - (fromEnd - idx));
        }
    }
    return true;
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin >> N >> K;

    for(int r =1; r <= N; r++) {
        for(int c =1; c <= N; c++) {
            cin >> color[r][c];
        }
    }

    int x, y, dir;
    for(int k =1; k <= K; k++) {
        cin >> x >> y >> dir;
        board[x][y][0] = k;
        length[x][y]++;
        token[k] = { x ,y ,dir} ;
    }

    bool flag = false;
    int turn = 1;
    for(turn = 1; turn <= 1000; turn++) {
        if(!moveToekn()) { flag = true; break; }
    }

    cout << (flag ? turn : -1);
    return 0;
}