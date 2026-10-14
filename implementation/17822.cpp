#include<bits/stdc++.h>
#define MX 55
using namespace std;
using pii = pair<int, int>;

int N, M, T, sum, Total, Answer, Avre;
int circle[MX][MX];
int c_circle[MX][MX];
bool processed[MX][MX];

vector<pair<pii, int>> cmd;

void copy_map(int a[][MX], int b[][MX]) {
    for(int i=1; i <= N; i++) {
        for(int j = 0; j < M; j++) {
            a[i][j] = b[i][j];
        }
    }
}

void turning(int idx, int dir, int k) {
    copy_map(c_circle, circle);
    if (dir == 0) {
        for (int i =0; i< M; i++) {
            int value = circle[idx][i];
            int pos = (i + k) % M;
            c_circle[idx][pos] = value;
        }
    }
    else {
        for(int i = 0; i < M; i++) {
            int value = circle[idx][i];
            int temp_k = k % M;
            int pos = i - temp_k;
            if (pos < 0) pos = pos + M; 
            c_circle[idx][pos] = value;
        }
    }
    copy_map(circle, c_circle);
}

bool bfs(int a, int b) {
    queue<pii> q; q.push({a, b});
    vector<pii> v; v.push_back({a, b});
    processed[a][b] = true;

    while(!q.empty()) {
        int c_num = q.front().first;
        int idx = q.front().second;
        q.pop();

        int left_idx= idx - 1;
        int right_idx = idx + 1;

        int left_circle = c_num - 1;
        int right_circle = c_num + 1;

        if (left_idx < 0) left_idx = M -1;
        if (right_idx >= M) right_idx = right_idx % M;

        if (circle[c_num][idx] == circle[c_num][left_idx]) {
            if(!processed[c_num][left_idx]) {
                processed[c_num][left_idx] = true;
                q.push({c_num, left_idx});
                v.push_back({c_num, left_idx});
            }
        }

        if (circle[c_num][idx] == circle[c_num][right_idx]) {
            if(!processed[c_num][right_idx]) {
                processed[c_num][right_idx] = true;
                q.push({c_num, right_idx});
                v.push_back({c_num, right_idx});
            }
        }

        if (left_circle > 0) {
            if(circle[c_num][idx] == circle[left_circle][idx]) {
                if(!processed[left_circle][idx]) {
                    processed[left_circle][idx] = true;
                    q.push({left_circle, idx});
                    v.push_back({left_circle, idx});
                }
            }
        }

        if (right_circle <= N) {
            if (circle[c_num][idx] == circle[right_circle][idx]) {
                if (!processed[right_circle][idx]) {
                    processed[right_circle][idx] = true;
                    q.push({right_circle, idx});
                    v.push_back({right_circle, idx});
                }
            }
        }
    }
    
    if (v.size() == 1) return false;
    else {
        for(const auto &cur: v) {
            circle[cur.first][cur.second] = 0;
        }
        return true;
    }
    
}

bool check_adjacency() {
    memset(processed, false, sizeof(processed));
    bool flag = false;

    for(int i = 1; i <= N; i++) {
        for(int j = 0; j< M; j++) {
            if(!processed[i][j] && circle[i][j] != 0) {
                bool T = bfs(i,j);
                if(T) flag = true;
            }
        }
    }
    return flag;
}

void change_value(double avr) {
    for(int i =1; i<= N; i++) {
        for(int j = 0; j < M; j++) {
            if(circle[i][j] == 0) continue;
            if((double)(circle[i][j]) > avr) circle[i][j]--;
            else if ((double)(circle[i][j]) < avr) circle[i][j]++;
        }
    }
}

pii calc() {
    pii r;
    for(int i=1; i<= N; i++) {
        for (int j =0; j< M; j++) {
            r.first = r.first + circle[i][j];
            if(circle[i][j] != 0) r.second++;
        }
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> T;
    for(int i = 1; i<= N; i++) {
        for(int j = 0; j< M; j++) {
            cin >> circle[i][j];
        }
    }
    Total = N * M;

    for(int i = 0; i< T; i++) {
        int a, b, c; cin >> a >> b >> c;
        cmd.push_back({{a, b}, c});
    }

    for (int i = 0; i < T; i++) {
        int num = cmd[i].first.first;
        int dir = cmd[i].first.second;
        int k = cmd[i].second;

        for(int j = num; j <= N; j += num) turning(j, dir, k);
        bool T = check_adjacency();
        if(!T) {
            pii temp = calc();
            temp = calc();
            double average = (double)(temp.first) / (double)(temp.second);
            change_value(average);
        }
    }
    cout << calc().first;

    return 0;
}