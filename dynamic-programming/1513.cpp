#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
using pii = pair<int,int>;

int N, M, C;
int mat[51][51];
int dp[51][51][51][51];
const int mod = 1000007;

int go(int y, int x, int cnt, int prev) {
    if(y > N || x > M) return 0;
    if (y == N && x == M) {
        if(cnt == 0 && mat[y][x] == 0) return 1;
        if(cnt == 1 && mat[y][x] > prev) return 1;
        return 0;
    }
    int &ret = dp[y][x][cnt][prev];
    if(ret != -1) return ret;
    ret = 0;
    if(mat[y][x] == 0) ret = (go(y+1, x, cnt, prev) + go(y, x+1, cnt, prev)) % mod;
    else if(mat[y][x] > prev) ret = (go(y+1, x, cnt - 1, mat[y][x]) + go(y,x+1, cnt -1, mat[y][x])) % mod;
    return ret;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    cin >> N >> M >> C;
    for(int i = 1; i <= C; i++) {
        int a, b; cin >> a >> b;
        mat[a][b] = i;
    }

    for (int i = 0; i <= C; i++) {
        cout << go(1, 1, i, 0) << " ";
    }


    return 0;
}