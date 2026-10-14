#include<iostream>
#include<algorithm>
using namespace std;

int n;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

int mat[10][10];
int processed[10][10];

int result = 1e7;

void dfs(int sum, int cnt) {
    if(cnt == 3) {
        result = min(result, sum);
        return;
    }

    for (int i = 0; i< n; i++) {
        for (int j = 0; j< n; j++) {
            int check = 0;
            int nx, ny;
            for (int k = 0; k< 4; k++) {
                nx =  j + dx[k];
                ny = i + dy[k];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if(processed[ny][nx]) continue;
                check++;
            }
            
            if(check == 4) {
                int ssum = mat[i][j];
                for(int k = 0; k < 4; k++) {
                    nx = j + dx[k];
                    ny = i + dy[k];
                    processed[ny][nx] = true;
                    ssum += mat[ny][nx];
                }
                processed[i][j] = true;
                dfs(sum + ssum, cnt + 1);
                for(int k = 0; k < 4; k++) {
                    nx = j + dx[k];
                    ny = i + dy[k];
                    processed[ny][nx] = false;
                }
                processed[i][j] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i< n; i++) {
         for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
         }
    }

    dfs(0, 0);
    cout << result;

    return 0;
}