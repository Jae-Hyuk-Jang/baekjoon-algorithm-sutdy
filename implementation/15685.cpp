#include<bits/stdc++.h>
using namespace std;
#define MX 101

int N, x, y, d, g, Sx, Sy;
int board[MX][MX];

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

vector<int> dir;

void make_curve() {
    int size = dir.size();
    for(int i = size - 1; i >= 0; i--) {
        int nd = (dir[i] + 1) % 4;
        x += dx[nd];
        y += dy[nd];
        board[x][y] = 1;
        dir.push_back(nd);
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i= 0; i < N; i++) {
        cin >> y >> x >> d >> g;
        dir.clear();

        board[x][y] = 1;
        x += dx[d];
        y += dy[d];
        board[x][y] = 1;

        dir.push_back(d);
        for(int j = 0; j < g; j++) make_curve();
    }

    int answer = 0;
    for(int i = 0; i < MX; i++) {
        for(int j = 0 ; j< MX; j++) {
            if(board[i][j] && board[i+1][j] 
                && board[i][j+1] && board[i+1][j+1]) answer++;
        }
    }

    cout << answer;
    return 0;
}
