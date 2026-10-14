#include<bits/stdc++.h>
#define MX 101
using namespace std;

int road1[MX][MX];
int road2[MX][MX];
int n, l;
int result = 0;

void passCnt(int road[101][101]) {
    for(int i = 0; i < n; i++)  {
        bool slope[101] = {0};
        bool possible = true;
        for(int h = 0; h < n -1; h++) {
            if(abs(road[i][h] - road[i][h+1]) > 1) {
                possible = false;
                break;
            }

            if(road[i][h] == road[i][h+1] + 1) {
                int cur_hight  = road[i][h+1];
                for(int k = h + 2; k < h + 1 + l; k++) {
                    if(k >= n || road[i][k] != cur_hight) {
                        possible = false;
                        break;
                    }
                }
                if(possible) slope[h+l] = true;
                else break;
            }

            if(road[i][h] == road[i][h+1] -1) {
                int cur_hight = road[i][h];
                for(int k = h; k > h - l; k--) {
                    if(k < 0 || road[i][k] != cur_hight || slope[k]) {
                        possible = false;
                        break;
                    }
                }
                if(!possible) break;
            }
        }

        if(possible) result++;
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> road1[i][j];
            road2[j][i] = road1[i][j];
        }
    }

    passCnt(road1);
    passCnt(road2);
    cout << result << '\n';

    return 0;
}