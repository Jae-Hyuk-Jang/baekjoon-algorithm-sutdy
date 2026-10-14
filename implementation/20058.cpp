#include<bits/stdc++.h>
#define MX 70
using namespace std;
using pii = pair<int,int>;

int N, Q, sum_answer, size_answer;
int mat[MX][MX];
bool processed[MX][MX];

vector<int> cmd;

int dx[] =  {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void turning(int a, int b, int len) {
    int square = len / 2;
    for(int num = 0; num < square; num++) {
        int start_x = a + num;
        int start_y = b + num;
        int end_x = a + len - num - 1;
        int end_y = b + len - num - 1;

        int x_idx = end_x;
        int y_idx = start_y;
        int idx = 0;
        vector<int> temp;
        for(int i = start_x; i < end_x; i++) temp.push_back(mat[i][start_y]);
        for(int i = start_x; i < end_x; i++) mat[i][start_y] = mat[end_x][y_idx++];
        for(int i = start_y; i < end_y; i++) mat[end_x][i] = mat[x_idx--][end_y];
        for(int i = end_x; i > start_x; i--) mat[i][end_y] = mat[start_x][y_idx--];
        for(int i = end_y; i > start_y; i--) mat[start_x][i] = temp[idx++];
    }
}

void turned(int len) {
    for(int i = 0; i < N; i += len) {
        for(int j = 0; j < N; j += len) {
            turning(i, j, len);
        }
    }
}

void melt() {
    vector<pii> v;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j< N; j++) {
            if(!mat[i][j]) continue;
            int cnt = 0;
            for(int k = 0; k< 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                if(!mat[nx][ny]) continue;
                cnt++;
            }
            if(cnt < 3) v.push_back({i, j});
        }
    }

    for(auto c : v) {
        mat[c.first][c.second]--;
        sum_answer--;
    }
}


int bfs(int a, int b) {
    queue<pii> q;
    q.push({a, b});
    processed[a][b] = true;
    int cnt = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && ny >= 0 && nx < N && ny < N) {
                if(mat[nx][ny] && !processed[nx][ny]) {
                    processed[nx][ny] = true;
                    q.push({nx, ny});
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

void calculate() {
    for(int i=0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!mat[i][j]) continue;
            if(processed[i][j]) continue;
            int result = bfs(i, j);
            size_answer = max(size_answer, result);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    N = (1 << N);

    for(int i  = 0; i < N; i++) {
        for(int j = 0; j< N; j++) {
            cin >> mat[i][j];
            sum_answer += mat[i][j];
        }
    }

    for(int i = 0; i< Q; i++) {
        int a; cin >> a;
        cmd.push_back(a);
    }

    for(int i = 0; i < Q; i++) {
        int L = (1 << cmd[i]);
        turned(L);
        melt();
    }
    calculate();

    cout << sum_answer << '\n' << size_answer;


    return 0;
}