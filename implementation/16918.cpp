#include<bits/stdc++.h>
#define MX 201 
using namespace std;

int R, C, N;
int boom_time[MX][MX];
char mat[MX][MX];

int dx[] = { 0, 0, 1, -1};
int dy[] = { 1, -1, 0, 0};

void install_boom(int T) {
    for (int i = 0; i< R; i++) {
        for(int j =0; j< C; j++) {
            if (mat[i][j] == 'O') continue;
            mat[i][j] = 'O';
            boom_time[i][j] = T  + 3;
        }
    }
}

void delete_boom(int T) {
    for (int i = 0; i< R; i++) {
        for (int j = 0; j < C; j++) {
            if (boom_time[i][j] == T) {
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
                    if (mat[nx][ny] == '.') continue;
                    mat[nx][ny] = '.';
                }
                mat[i][j] = '.';
                boom_time[i][j] = 0;
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C >> N;
    for(int i = 0; i< R; i++) {
        for(int j = 0; j< C; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 'O') { boom_time[i][j] = 3;}
        }
    }

    int time = 2;
    while(true) {
        if (time == N + 1) break;
        if (time % 2 == 0) install_boom(time);
        else delete_boom(time);
        time++;
    } 
    for(int i = 0; i< R; i++) {
        for (int j = 0; j< C; j++) {
            cout << mat[i][j];
        }
        cout << '\n';
    }

    return 0;
}