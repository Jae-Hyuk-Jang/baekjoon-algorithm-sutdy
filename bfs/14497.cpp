#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#define MX 310

using namespace std;
using pii = pair<int,int>;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int n, m, sx, sy, ex, ey;
int visited[MX][MX];
int ret; 
queue<int> q;
char a[MX][MX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> sy >> sx >> ey >> ex;
    sy--, sx--, ey--, ex--;
    for(int i = 0; i< n; i++) {
        string str; cin >> str;
        for(int j = 0; j< m; j++) {
            a[i][j] = str[j];
        }
    }

    q.push(1000*sy + sx);
    visited[sy][sx] = 1;
    int cnt = 0;

    while(a[ey][ex] != '0') {
        cnt++;
        queue<int> temp;
        while(q.size()) {
            int y = q.front() / 1000;
            int x = q.front() % 1000;
            q.pop();

            for(int i = 0; i< 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
                visited[ny][nx] = cnt;
                if(a[ny][nx] != '0') {
                    a[ny][nx] = '0';
                    temp.push(1000 * ny + nx);
                }
                else q.push(1000* ny + nx);
            }
        }
        q = temp;
    }

    cout << visited[ey][ex];

    return 0;
}