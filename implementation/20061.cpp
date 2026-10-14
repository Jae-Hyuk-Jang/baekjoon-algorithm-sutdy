#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int area[10][4][2];
int N, block_cnt, score, figure_num = 1;
vector<pair<int, pii>> v;

void input() {
    cin >> N;
    for (int i = 0; i< N; i++) {
        int a, b ,c; cin >> a >> b >> c;
        v.push_back({a, {b, c}});
    }
}

void setting_block(int shape, int x, int y) {
    if (shape == 1) {
        int b_idx = y  + 1;
        while(b_idx < 10 && area[b_idx][x][0] == 0) b_idx++;
        b_idx--;
        area[b_idx][x][0] = figure_num;

        int g_idx = x + 1;
        while(g_idx < 10 && area[g_idx][y][1] == 0) g_idx++;
        g_idx--;
        area[g_idx][y][1] = figure_num++;
        block_cnt += 2;
    } 
    else if(shape == 2) {
        int b_idx =  y + 2;
        while(b_idx < 10 && area[b_idx][x][0] == 0) b_idx++;
        b_idx--;
        area[b_idx][x][0] = figure_num;
        area[b_idx - 1][x][0] = figure_num;

        int g_idx = x + 1;
        while (g_idx < 10 && area[g_idx][y][1] == 0 && area[g_idx][y+1][1] == 0) g_idx++;
        g_idx--; 
        area[g_idx][y][1] = figure_num;
        area[g_idx][y+1][1] = figure_num++;
        block_cnt += 4;
    }
    else {
        int b_idx = y + 1;
        while (b_idx < 10 && area[b_idx][x][0] == 0 && area[b_idx][x + 1][0] == 0) b_idx++;
        b_idx--;
        area[b_idx][x][0] = figure_num;
        area[b_idx][x + 1][0] = figure_num;

        int g_idx = x + 2;
        while(g_idx < 10 && area[g_idx][y][1] == 0) g_idx++;
        g_idx--;
        area[g_idx][y][1] = figure_num;
        area[g_idx-1][y][1] = figure_num++;
        block_cnt += 4;
    }
}

void remove(int idx, int color) {
    for (int i = 0; i < 4; i++) {
        if (area[idx][i][color] == 0) continue;
        area[idx][i][color] = 0;
        block_cnt--;
    }
}

pii find_partner(int idx, int pos, int color) {
    if (color == 0) {
        for(int i = 0; i < 4; i++) {
            int n_idx = idx + dx[i];
            int n_pos = pos + dy[i];
            if(n_idx >= 4 && n_idx < 10 && n_pos >= 0  && n_pos < 4) {
                if (area[idx][pos][color] == area[n_idx][n_pos][color]) {
                    if (idx == n_idx) return { 3, i };
                    return { 2, i };
                }
            }
        }
        return { 1, -1 };
    }
    for (int i = 0; i < 4; i++) {
        int n_idx = idx + dx[i];
        int n_pos = pos + dy[i];
        if (n_idx >= 4 && n_idx < 10 && n_pos >= 0 && n_pos < 4) {
            if (area[idx][pos][color] == area[n_idx][n_pos][color]) {
                if (idx == n_idx) return { 2, i };
                return { 3, i };
            }
        }
    }
    return { 1, -1 };
}

void move(int index, int color) {
    if (index == 3) return;
    int idx = index - 1;
    for (int i = 0; i< 4; i++) {
        if (area[idx][i][color] == 0) continue;
        int pos = i;
        pii shape = find_partner(idx, pos, color);

        if (shape.first == 1) {
            int n_idx = idx + 1;
            area[n_idx][i][color] = area[idx][i][color];
            area[idx][i][color] = 0;
        }
        else if (shape.first == 2) {
            int p_idx = idx + dx[shape.second];
            if (color == 0) {
                int standard_idx = max(p_idx, idx);
                int partner_idx = min(p_idx, idx);
                int n_idx = standard_idx + 1;
                int nP_idx = partner_idx + 1;
                area[n_idx][i][color] = area[standard_idx][i][color];
                area[nP_idx][i][color] = area[partner_idx][i][color];
                area[partner_idx][i][color] = 0;
            } else {
                int n_idx = idx + 1;
                int nP_idx = p_idx + 1;
                area[n_idx][i][color] = area[idx][i][color];
                area[nP_idx][i][color] = area[p_idx][i][color];
                area[idx][i][color]= 0;
                area[p_idx][i][color] = 0;
            }
        }
        else {
            int p_idx = idx + dx[shape.second];
            if (color == 0) {
                int n_idx = idx + 1;
                int np_idx = p_idx + 1;
                area[n_idx][i][color] = area[idx][i][color];
                area[np_idx][i][color] = area[p_idx][i][color];
                area[idx][i][color] = 0;
                area[p_idx][i][color]= 0;
            } else {
                int standard_idx = max(idx, p_idx);
                int partner_idx = min(idx, p_idx);
                int n_idx = standard_idx + 1;   // 수정됨
                int nP_idx = partner_idx + 1;
                area[n_idx][i][color] = area[standard_idx][i][color];
                area[nP_idx][i][color] = area[partner_idx][i][color];
                area[partner_idx][i][color] = 0;
            }
        }
    }
    move(index -1, color);
}

void remove_full_block() {
    bool flag = false;
    for (int color = 0; color < 2; color++) {
        for (int i = 4; i < 10; i++) {
            int cnt =0;
            for (int j = 0; j < 4; j++) {
                if (area[i][j][color] == 0) break;
                cnt++;
            }
            if (cnt == 4) {
                flag= true;
                score++;
                remove(i, color);
                move(i, color);
            }
        }
    }
    if(flag) remove_full_block();
}

void check_special_point() {
    for(int color = 0; color < 2; color++) {
        int cnt = 0;
        for(int i = 4; i < 6; i++) {
            for (int j = 0; j< 4; j++) {
                if (area[i][j][color] == 0) continue;
                cnt++;
                break;
            } 
        }
        for(int i =0; i<cnt; i++) {
            remove(9, color);
            move(9, color);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    for (int i = 0; i< v.size(); i++) {
        int t = v[i].first;
        int x = v[i].second.first;
        int y = v[i].second.second;
        setting_block(t, x, y);
        remove_full_block();
        check_special_point();
    }
    cout << score << '\n' << block_cnt;
    return 0;
}
