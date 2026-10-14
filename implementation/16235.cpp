#include<bits/stdc++.h>
#define MX 11
using namespace std;

int N, M, K;
int energy[MX][MX];
int insert_energy[MX][MX];

vector<int> mat[MX][MX];

int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void spring_summer() {
    for(int i = 1; i<= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(mat[i][j].size() == 0) continue;

            int die_energy = 0;
            vector<int> temp;
            sort(mat[i][j].begin(), mat[i][j].end());
            
            for(int k = 0; k < mat[i][j].size(); k++) {
                int age = mat[i][j][k];
                if(energy[i][j] >= age) {
                    energy[i][j] = energy[i][j] - age;
                    temp.push_back(age+1);
                }
                else {
                    die_energy = die_energy + (age/ 2);
                }
            }

            mat[i][j].clear();
            for(int k : temp) mat[i][j].push_back(k);
            energy[i][j] += die_energy;
        }
    }
}

void fall() {
    for(int i = 1; i<= N; i++) {
        for(int j =1; j <= N; j++) {
            if(mat[i][j].size() == 0) continue;
            for(int age : mat[i][j]) {
                if(age % 5 ==0) {
                    for(int a = 0; a < 8; a++) {
                        int nx = i + dx[a];
                        int ny = j + dy[a];

                        if(nx >= 1 && ny >= 1 && nx <= N && ny <= N) {
                            mat[nx][ny].push_back(1);
                        }
                    }
                }
            }
        }
    }
}
void winter() {
    for(int i= 1; i<= N; i++) {
        for(int j =1; j <= N; j++) {
            energy[i][j] += insert_energy[i][j];
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> insert_energy[i][j];
            energy[i][j] = 5;
        }
    }

    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        mat[a][b].push_back(c);
    }


    for(int i = 0; i < K; i++) {
        spring_summer();
        fall();
        winter();
    }

    int answer = 0;
    for(int i =1; i <= N; i++) {
        for(int j =1; j <= N; j++) {
            answer += mat[i][j].size();
        }
    }

    cout << answer;

    return 0; 
}