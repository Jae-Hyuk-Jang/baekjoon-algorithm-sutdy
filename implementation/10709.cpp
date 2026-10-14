#include<iostream>
#include<algorithm>
using namespace std;

int h, w;
int mat[101][101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> h >> w;
    for(int i = 1; i<= h; i++) {
        for (int j = 1; j<= w; j++) {
            char c; cin >> c;
            if(c == 'c') mat[i][j] = 0;
            else mat[i][j] = -1;
        }
    }

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if(mat[i][j] == -1 || mat[i][j] > 0) continue;
            int temp = 1;
            for (int k = j + 1; k <= w; k++) {
                if(mat[i][k] == -1) mat[i][k] = temp;
                else mat[i][k] = min(mat[i][k], temp);
                temp++;
            }
        }
    }

    for(int i = 1; i <= h; i++) {
        for (int j =1; j <= w; j++) {
            cout << mat[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
