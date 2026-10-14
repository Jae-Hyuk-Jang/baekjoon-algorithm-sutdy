#include <bits/stdc++.h>
using namespace std;

int n;
int mat[22][22];
bool processed[22][22];
int dx[] = {0, -1, 1, 0};
int dy[] = {-1, 0, 0, 1};

int bx, by; 
int result = 0; 
int eatCnt = 0; 
int sz = 2;    

bool stop = false;

struct Node {
    int x, y, dist;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 9) {
                by = i; 
                bx = j; 
                mat[i][j] = 0; 
            }
        }
    }

    while (true) {
        memset(processed, 0, sizeof(processed));
        queue<Node> q;
        q.push({bx, by, 0});
        processed[by][bx] = true;

        int targetX = -1, targetY = -1, minDist = 1e9;
        bool found = false;

        while (!q.empty()) {
            Node cur = q.front();
            q.pop();

            if (mat[cur.y][cur.x] > 0 && mat[cur.y][cur.x] < sz) {
                if (cur.dist < minDist) {
                    minDist = cur.dist;
                    targetX = cur.x;
                    targetY = cur.y;
                    found = true;
                } else if (cur.dist == minDist) {
                    if (cur.y < targetY || (cur.y == targetY && cur.x < targetX)) {
                        targetX = cur.x;
                        targetY = cur.y;
                    }
                }
            }

   
            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !processed[ny][nx]) {
                    if (mat[ny][nx] <= sz) {
                        processed[ny][nx] = true;
                        q.push({nx, ny, cur.dist + 1});
                    }
                }
            }
        }

        if (!found) break; 


        result += minDist;
        bx = targetX;
        by = targetY;
        mat[by][bx] = 0;
        eatCnt++;

        if (eatCnt == sz) {
            sz++;
            eatCnt = 0;
        }
    }

    cout << result << "\n";
    return 0;
}
