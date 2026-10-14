#include<bits/stdc++.h>
#define INF 1e9
using namespace std;

int N, M, H, answer;
int mat[11][30];
bool processed[11][30];

bool possible() {
    for (int i = 1; i <= N; i++) {
        int cur = i;
        for(int j = 1; j <= H; j++) {
            if(processed[cur][j]) cur = cur + 1;
            else if(processed[cur-1][j]) cur = cur - 1;
        }
        if(cur != i) return false;
    }
    return true;
}

void dfs(int idx, int cnt) {
    if(cnt >= 4) return;
    if(possible()) {
        answer = min(answer, cnt);
        return;
    }

    for(int i = idx; i <= H; i++) {
        for(int j = 1; j < N; j++) {
            if(processed[j][i]) continue;
            if(processed[j-1][i]) continue;
            if(processed[j+1][i]) continue;
            processed[j][i] = true;
            dfs(i, cnt+1);
            processed[j][i] = false;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    answer = INF;
    cin >> N >> M >> H;
    for(int i=0; i< M; i++) {
        int a, b; cin >> a >> b;
        processed[b][a] = true;
    }

    dfs(1, 0);
    if(answer == INF) answer = -1;
    cout << answer;

    return 0;
}