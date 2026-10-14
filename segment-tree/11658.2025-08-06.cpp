#include<bits/stdc++.h>
#define MX 1025
using namespace std;

int N, Q;
int mat[MX][MX];
int tree[MX][MX];

int init(int row, int col) {
    int result = 0;
    for(int r = row; r > 0; r -= (r& -r)) {
        for(int c = col; c > 0; c -= (c & -c)) {
            result += tree[r][c];
        }
    }
    return result;
}

void update(int row, int col, int num) {
    for(int r = row; r <= N; r += (r& -r)) {
        for(int c = col; c <= N; c += (c & -c)) {
            tree[r][c] += num;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    memset(tree, 0, sizeof tree);
    
    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= N; c++) {
            cin >> mat[r][c];
            update(r, c, mat[r][c]);
        }
    }

    while(Q--) {
        int w; cin >> w;
        if(w == 0) {
            int r1, c1, num; cin >> r1 >> c1 >> num;
            update(r1, c1, num - mat[r1][c1]);
            mat[r1][c1] = num;
        }
        else if (w == 1) {
            int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
            int answer = init(r2, c2) - init(r2, c1 -1) - init(r1 - 1, c2) + init(r1 -1, c1 -1);
            cout << answer << '\n';
        }
    }

    return 0;
}