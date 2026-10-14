#include<bits/stdc++.h>
#define MX 51
#define INF 1e9
using namespace std;
using pii = pair<int,int>;

int N, M, empty_place, answer = INF;
int mat[MX][MX];
int Time[MX][MX];
bool selected[10];

vector<pii> virus;

int dx[] = { 0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void spread(queue<pii> q) {
    int infect_place = 0;
    int total_time = 0;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && ny >= 0 && nx < N && ny < N) {
                if(mat[nx][ny] != 1 && Time[nx][ny] == -1) {
                    Time[nx][ny] = Time[x][y] + 1;
                    if(mat[nx][ny] == 0) {
                        infect_place++;
                        total_time = Time[nx][ny];
                    }
                    q.push({nx, ny});
                }
            }

        }
    }
    if(infect_place == empty_place) answer = min(answer, total_time);
}

void select_virus(int idx, int cnt) {
    if(cnt == M) {
        queue<pii> q;
        memset(Time, -1, sizeof(Time));
        for(int i = 0; i< virus.size(); i++) {
            if(selected[i]) {
                q.push(virus[i]);
                Time[virus[i].first][virus[i].second] = 0;
            }
        }
        spread(q);
        return;
    }

    for(int i = idx; i < virus.size(); i++) {
        if(selected[i]) continue;
        selected[i] = true;
        select_virus(i + 1, cnt + 1);
        selected[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0; i< N; i++) {
        for(int j = 0; j< N; j++) {
            cin >> mat[i][j];
            if(mat[i][j] == 0) empty_place++;
            else if(mat[i][j] == 2) virus.push_back({i, j});
        }
    }
    select_virus(0, 0);
    cout << ((answer == INF) ? -1 : answer);

    return 0;
}