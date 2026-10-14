#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define MX 101

char mat[MX][MX];
bool processed[MX][MX];
int n;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void bfs(int i, int j) {

    queue<pair<int, int>> Q;
    Q.push({ i,j });
    processed[i][j] = 1;

    while (!Q.empty()) {
        auto cur = Q.front(); 
        Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (processed[nx][ny] || mat[i][j] != mat[nx][ny]) continue;

            processed[nx][ny] = 1;
            Q.push({ nx,ny });
        }
    }
}

int area() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!processed[i][j]) {
                cnt++;
                bfs(i, j);
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    int not_g = area(); 
    for (int i = 0; i < n; i++) fill(processed[i], processed[i] + n, 0);

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 'G')
                mat[i][j] = 'R';
        }
    }

    int is_g = area(); 
    cout << not_g << ' ' << is_g;

    return 0;
}