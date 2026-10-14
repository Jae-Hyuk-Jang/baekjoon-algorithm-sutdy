#include<bits/stdc++.h>
#define MX 510
using namespace std;

int N, Answer;
int mat[MX][MX];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int xdx[4][10] = {
    {-1, 1, -1 , 1, -1, 1, -2, 2, 0, 0},
    {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0},
    {0, 0, 1, 1, 2, 2, 1, 1, 3, 2},
    {0, 0, -1, -1, -2, -2, -1, -1, -3, -2}
};

int ydy[4][10] = {
    {0, 0, 1, 1, 2, 2, 1, 1, 3, 2},
    {0, 0, -1, -1, -2, -2, -1, -1, -3, -2},
    {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0},
    {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0}
};

int percent[9] = { 1, 1, 7, 7, 10, 10, 2, 2, 5};

int changeDir(int dir) {
    if (dir == 0) return 3;
    if (dir == 1) return 2;
    if (dir == 2) return 0;
    if (dir == 3) return 1;
} 

void spread(int x, int y, int dir) {
    int xx = x + dx[dir];
    int yy = y + dy[dir];

    if(!mat[xx][yy]) return;

    int sand = mat[xx][yy];
    int temp = sand;

    for(int i = 0; i< 9; i++) {
        int nx = x + xdx[dir][i];
        int ny = y + ydy[dir][i];
        int per = percent[i];
        int plus = (temp * per) / 100;

        if(nx < 1 || ny < 1 || nx > N || ny > N) Answer += plus;
        else mat[nx][ny] += plus;
        sand -= plus;
    }

    int nx = x + xdx[dir][9];
    int ny = y + ydy[dir][9];

    if(nx < 1 || ny < 1 || nx > N || ny > N) Answer += sand;
    else mat[nx][ny] += sand;

    mat[xx][yy] = 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> mat[i][j];
        }
    }

    int x = (N + 1) / 2;
    int y = (N + 1) / 2;
    int Dir = 1;
    int move_cnt = 1;

    while(1) {
        for(int i = 0; i< 2; i++) {
            for(int j = 0; j< move_cnt; j++) {
                spread(x, y, Dir);
                x += dx[Dir];
                y += dy[Dir];
            }
            Dir = changeDir(Dir);
        }

        move_cnt++;
        if(move_cnt == N) {
            for(int j = 0; j < move_cnt; j++) {
                spread(x, y, Dir);
                x += dx[Dir];
                y += dy[Dir];
            }
            break;
        } 
    }
    cout << Answer;
 
    return 0;
}