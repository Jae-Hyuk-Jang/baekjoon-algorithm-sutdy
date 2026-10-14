#include<bits/stdc++.h>
#define MX 25
using namespace std;

int n, m, k, answer;
int mat[MX][MX];
bool processed[MX][MX];

int dice[7] = {0, 1, 2, 3, 4, 5, 6};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int reverseDir(int d) {
    switch(d) {
        case 0: return 1;
        case 1: return 0;
        case 2: return 3;
        case 3: return 2;
    }
}

int changeDir(int d, int ret) {
    if(ret>0) {
        switch(d) {
            case 0: return 2;
            case 1: return 3;
            case 2: return 1;
            case 3: return 0;
        }
    }
    else if(ret < 0) {
        switch (d) {
            case 0: return 3;
            case 1: return 2;
            case 2: return 0;
            case 3: return 1;
        }
    }
    return d;
}

void getScore(int a, int b) {
    memset(processed, false, sizeof(processed));

    int num = mat[a][b];
    int cnt = 1;

    queue<pair<int,int>> q;
    q.push({a, b});
    processed[a][b] = true;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i= 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if(mat[nx][ny] == num && !processed[nx][ny]) {
                    processed[nx][ny] = true;
                    cnt++;
                    q.push({nx, ny});
                }
            }
        }
    }
    answer += (num *cnt);
}

void updateDice(int d) {
    int d1 = dice[1]; int d2 = dice[2]; int d3 = dice[3];
    int d4 = dice[4]; int d5 = dice[5]; int d6 = dice[6];

    switch (d)
    {
        case 0:
        dice[1] = d4;
        dice[4] = d6;
        dice[6] = d3;
        dice[3] = d1;
        break;
        case 1:
        dice[1] = d3;
        dice[3] = d6;
        dice[6] = d4;
        dice[4] = d1;
        break;
        case 2:
        dice[1] = d2;
        dice[2] = d6;
        dice[6] = d5;
        dice[5] = d1;
        break;
        case 3:
        dice[1] = d5;
        dice[5] = d6;
        dice[6] = d2;
        dice[2] = d1;
        break;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for(int i= 0; i< n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    int x =0, y= 0, d = 0;
    for(int i = 0; i < k; i++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m) {
             d = reverseDir(d);
             nx = x + dx[d];
             ny = y + dy[d];
        }
        getScore(nx, ny);
        updateDice(d);
        d = changeDir(d, dice[6] - mat[nx][ny]);
        x = nx; y = ny;
    }
    cout << answer;

    return 0;
}