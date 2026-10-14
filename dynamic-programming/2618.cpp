#include<algorithm>
#include<cstdio>

#define MX 1003
using namespace std;

int n, w, px[MX], py[MX], dp[MX][MX], y, x;

int d(int a, int b) {
    return abs(px[a] - px[b]) + abs(py[a] - py[b]);
}

int getSum(int a, int b) {
    if(a == w + 1 || b == w + 1) return 0;
    if(dp[a][b]) return dp[a][b];
    int next = max(a, b) + 1;
    return dp[a][b] = min(getSum(a, next) + d(b, next), getSum(next, b) + d(a, next));
}

void solve() {
    int a = 0, b =1;
    for(int i = 2; i < w + 2; i++) {
        if(dp[i][b] + d(a, i) < dp[a][i] + d(b, i)) puts("1"), a = i;
        else puts("2"), b = i;
    }
    return;
}

int main() {
    scanf_s("%d %d", &n, &w);
    px[0] = 1, py[0] = 1, px[1] = n, py[1] = n;
    for(int i = 2; i < w + 2; i++) scanf_s("%d %d", &y, &x), px[i] = x, py[i] =y;
    printf_s("%d\n", getSum(0, 1));
    solve();

    return 0;
}