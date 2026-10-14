#include<bits/stdc++.h>
#define MX 501
using namespace std;
using pii = pair<int,int>;

int N;
pii matrix[MX];
int dp[MX][MX];
pii dp_mat[MX][MX];

int _sum(int dx, int mid, int dy) {
    return dp_mat[dx][mid].first * dp_mat[dx][mid].second * dp_mat[mid+1][dy].second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=1; i<= N; i++) {
        cin >> matrix[i].first >> matrix[i].second;
        dp_mat[i][i] = matrix[i];
    }


    for(int i=1; i<= N; i++) {
        for(int dx = 1; dx + i <= N; dx++) {
            int dy = dx + i;
            dp[dx][dy] = 1e9;
            for(int mid = dx; mid < dy; mid++) {
                dp[dx][dy] = min(dp[dx][dy], dp[dx][mid] + dp[mid + 1][dy] + _sum(dx, mid, dy));
            }
            dp_mat[dx][dy].first = matrix[dx].first;
            dp_mat[dx][dy].second = matrix[dy].second;
        }
    }
    cout << dp[1][N];
    return 0;
}