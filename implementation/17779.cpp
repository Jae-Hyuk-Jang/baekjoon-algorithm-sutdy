#include<bits/stdc++.h>
#define MX 21
#define INF 1e9
using namespace std;

struct coord {
    int x, y;
};

int N, answer =INF;
int mat[MX][MX];
int label[MX][MX];
coord pos[4];

bool possible(int x, int y, int d1, int d2) {
    if(x + d1 >= N || y - d1 < 0) return false;
    if(x + d2 >= N  || y + d2 >= N) return false;
    if(x + d1 + d2 >= N || y - d1 + d2 >= N) return false;
    if(x + d2 + d1 >= N || y + d2 - d1 < 0) return false;
    return true;
}

void lableing(int a, int b, int c, int d) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            label[i][j] = 5;
        }
    }

    int sub = 0;
    for(int i = 0; i < pos[1].x; i++) {
        if (i >= pos[0].x) sub++;
        for(int j = 0; j<= pos[0].y - sub; j++) {
            label[i][j] = 1;
        }
    }

    int plus = 0;
    for(int i=0; i <= pos[2].x; i++) {
        if (i > pos[0].x) plus++;
        for(int j = pos[0].y + 1 + plus; j < N; j++) {
            label[i][j] = 2;
        }
    }

    sub = 0;
    for(int i = N -1; i >= pos[1].x; i--) {
        if(i < pos[3].x) sub++;
        for(int j = 0; j < pos[3].y - sub; j++) {
            label[i][j] = 3;
        }
    }

    plus = 0;
    for(int i= N -1; i > pos[2].x; i--) {
        if (i <= pos[3].x) plus++;
        for(int j = pos[3].y + plus; j < N; j++) {
            label[i][j] = 4;
        }
    }

    int sum[6] = {0, 0, 0, 0, 0, 0};
    for(int i = 0; i< N; i++) {
        for(int j =0; j< N; j++) {
            sum[label[i][j]] += mat[i][j];
        }
    }
    sort(sum, sum + 6);
    int diff = sum[5] - sum[1];
    answer = min(answer, diff);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >>N;
    for(int i=0; i< N; i++) {
        for(int j = 0; j< N; j++) {
            cin >> mat[i][j];
        }
    }

    for(int i = 0; i< N; i++) {
        for(int j = 1; j < N; j++) {
            for(int D1 = 1; D1 <= j; D1++) {
                for(int D2 = 1; D2 < N - j; D2++) {
                    if(possible(i, j, D1, D2)) {
                        pos[0].x = i, pos[0].y = j;
                        pos[1].x = i + D1, pos[1].y = j - D1;
                        pos[2].x = i + D2, pos[2].y = j + D2;
                        pos[3].x = i + D1 + D2, pos[3].y = j - D1 + D2;
                        lableing(i, j, D1, D2);
                    }
                }
            }
        }
    }
    cout << answer;
    return 0;
}