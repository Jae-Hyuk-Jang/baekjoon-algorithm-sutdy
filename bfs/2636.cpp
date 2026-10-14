#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
using pii = pair<int, int>;

int h, w;
int mat[110][110];
bool processed[110][110];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> h >> w;
    bool ch = false;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> mat[i][j];
        }
    }

    int year = 0;
    int last = 0;

    while(1) {
        int  cheese = 0;
        for (int i = 1; i<= h; i++) {
            for (int j = 1; j <= w; j++) {
                if(mat[i][j] == 1) cheese++;
            }
        }

        if(cheese == 0) break;
        last = cheese;

        memset(processed, 0, sizeof(processed));
        queue<pii> q;
        q.push({0, 0});
        processed[0][0] = true;

        vector<pii> melt;
        while(!q.empty()) {
            auto [x, y] = q.front(); q.pop();

            for (int k = 0; k< 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx < 0 || ny < 0 || nx > h + 1 || ny > w + 1) continue;;
                if(processed[nx][ny]) continue;

                if(mat[nx][ny] == 0) {
                    processed[nx][ny] = true;
                    q.push({nx, ny});
                } else if(mat[nx][ny] == 1) {
                    processed[nx][ny] = true;
                    melt.push_back({nx, ny});
                }
            }
        }
        for(const auto &[x, y]: melt) {
                mat[x][y] = 0;
            }
        year++;
    }

    cout << year << '\n' << last;

    return 0;
}