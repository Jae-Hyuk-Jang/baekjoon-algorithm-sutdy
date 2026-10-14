#include<bits/stdc++.h>
#define MX 510
using namespace std;
using ll = long long;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

int r,c; 
ll answer;
ll v[MX][MX], ch[MX][MX];

void dfs(int y, int x) {
    if(y == r - 1 && x == c -1)  return;
    
    if(ch[y][x] != -1) return;

    ch[y][x] = 0;

    for(int i= 0; i< 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
        if(v[y][x] <= v[ny][nx]) continue;

        if(ch[ny][nx] == -1) dfs(ny, nx); 
        ch[y][x] += ch[ny][nx];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;
    memset(ch, -1, sizeof ch);
    for(int y= 0; y < r; y++) {
        for(int x = 0; x < c; x++) {
            cin >> v[y][x];
        }
    }

    ch[r-1][c-1] = 1;
    dfs(0, 0);
    cout << ch[0][0];

    return 0;
}