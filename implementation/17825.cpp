#include<bits/stdc++.h>
#define MX 11
using namespace std;


struct state {
    int prev, next, start_circle;
    bool select_circle, finish;
};

struct yut {
    int blue_circle, pos, score;
    bool finish;
};

int Answer;
int command[MX];
int move_num[4];
int mat_score[4][30];
bool processed[4][30];
bool special_point[4][30];

yut _yut[4];

void setting() {
    move_num[0] = 21; move_num[1] = 13; move_num[2] = 17; move_num[3] = 23;

    special_point[1][9] = special_point[1][10] = special_point[1][11] = special_point[1][12] = true;
    special_point[2][13] = special_point[2][14] = special_point[2][15] = special_point[2][16] = true;
    special_point[3][19] = special_point[3][20] = special_point[3][21] = special_point[3][22] = true;
    special_point[0][1] = special_point[0][2] = special_point[0][3] = special_point[0][4] = special_point[0][20] = true;

    for(int i = 1; i <= 20; i++) mat_score[0][i] = 2 * i;
    mat_score[1][6]  = 13; mat_score[1][7] = 16; mat_score[1][8] = 19; mat_score[1][9] = 25;
    mat_score[1][10] = 30; mat_score[1][11] =35; mat_score[1][12] = 40;
    mat_score[2][11] = 22; mat_score[2][12] = 24; mat_score[2][13] = 25; mat_score[2][14] = 30; 
    mat_score[2][15] = 35; mat_score[2][16] = 40;
    mat_score[3][16] = 28; mat_score[3][17] = 27; mat_score[3][18] = 26; mat_score[3][19] = 25; 
    mat_score[3][20] = 30; mat_score[3][21] = 35; mat_score[3][22] = 40; 
    
    for(int i = 1; i<= 5; i++) mat_score[1][i] = mat_score[0][i];
    for(int i = 1; i<= 10; i++) mat_score[2][i] = mat_score[0][i];
    for(int i = 1; i<= 15; i++) mat_score[3][i] = mat_score[0][i];
}

void input() {
    for(int i = 0; i< 10; i++) cin >> command[i];
}

state getState(int idx, int c_idx) {
    int prev = _yut[idx].pos;
    int next = _yut[idx].pos + command[c_idx];
    int start_circle = _yut[idx].blue_circle;
    bool select_circle = false;
    bool finish = false;

    if(start_circle == 0) {
        if (prev == 5 || prev == 10 || prev == 15) {
            select_circle = true;
            start_circle = prev/5;
        }
    }
    if(next >= move_num[start_circle]) finish = true;

    return { prev, next, start_circle, select_circle, finish };
}

bool check_special_point(int circle, int pos) {
    if (circle == 0) {
        if (pos == 20) {
            if(processed[1][12] || processed[2][16] || processed[3][22]) return false;
        } else {
            if (processed[0][pos]) return false;
        }
    } else if (circle == 1) {
        if(processed[2][pos+4] || processed[3][pos+10]) return false;
        if (pos == 12) {
            if (processed[0][20]) return false;
        }
    } else if (circle == 2) {
        if (processed[1][pos - 4] || processed[3][pos+6]) return false;
        if (pos == 16) {
            if(processed[0][20]) return false;
        }

    } else if (circle == 3) {
        if (processed[1][pos -10] || processed[2][pos -6]) return false;
        if (pos == 22) {
            if (processed[0][20]) return false;
        }
    }
    return true;
}


bool check_processed(state s, int idx) {
    if(special_point[s.start_circle][s.next]) {
        if (!check_special_point(s.start_circle, s.next)) return false;
    }

    if (processed[s.start_circle][s.next]) return false;
    return true;
}

void makeState(state s, int idx, bool T) {
    if(T) {
        if(s.finish) {
            processed[s.start_circle][s.prev] = false;
            _yut[idx].pos = s.next;
            _yut[idx].finish = true;
        } else {
            if (s.select_circle) {
                _yut[idx].blue_circle = s.start_circle;
                processed[0][s.prev] = false;
            } else {
                processed[_yut[idx].blue_circle][s.prev] = false;
            }
            processed[_yut[idx].blue_circle][s.next] = true;
            _yut[idx].pos = s.next;
            _yut[idx].score = _yut[idx].score + mat_score[_yut[idx].blue_circle][s.next];
        }
    } else {
        if(s.finish) {
            processed[s.start_circle][s.prev] = true;
            _yut[idx].pos = s.prev;
            _yut[idx].finish = false;
        } else {
            if (s.select_circle) {
                processed[0][s.prev] = true;
                processed[_yut[idx].blue_circle][s.next] = false;
                _yut[idx].pos = s.prev;
                _yut[idx].score = _yut[idx].score - mat_score[_yut[idx].blue_circle][s.next];
                _yut[idx].blue_circle = 0;
            } else {
                processed[_yut[idx].blue_circle][s.prev] = true;
                processed[_yut[idx].blue_circle][s.next] = false;
                _yut[idx].pos = s.prev;
                _yut[idx].score = _yut[idx].score - mat_score[_yut[idx].blue_circle][s.next];
            }
        }
    }
}

void dfs(int cnt) {
    if (cnt == 10) {
        int temp = 0;
        for(int i = 0; i < 4; i++) temp = temp + _yut[i].score;
        if(Answer < temp) Answer =temp;
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (_yut[i].finish) continue;
        state _state = getState(i, cnt);
        if(!check_processed(_state, i)) continue;

        makeState(_state, i, true);
        dfs(cnt + 1);
        makeState(_state, i, false);
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    setting();
    input();
    dfs(0);
    cout << Answer;

    return 0;
}