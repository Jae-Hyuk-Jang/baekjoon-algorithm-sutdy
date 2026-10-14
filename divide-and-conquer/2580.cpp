#include<bits/stdc++.h>
using namespace std;

int mat[10][10];
bool c1[10][10], c2[10][10], c3[10][10];
int cnt = 0;
struct pos { int x, y; };
pos arr[100];
bool complete = false;

int square(int x, int y) {
	return (x / 3) * 3 + (y / 3);
}

void sudoku(int idx) {
	if (idx == cnt) {

		complete = true;
		return;
	}

	int x = arr[idx].x, y = arr[idx].y;
	if (mat[x][y]) sudoku(idx + 1);
	for (int num = 1; num <= 9; num++) {
		if (c1[x][num] || c2[y][num] || c3[square(x, y)][num]) continue;
		c1[x][num] = c2[y][num] = c3[square(x, y)][num] = true;
		mat[x][y] = num;
		sudoku(idx + 1);
		if (complete) return;
		c1[x][num] = c2[y][num] = c3[square(x, y)][num] = false;
		mat[x][y] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> mat[i][j];
			if (mat[i][j]) {
				c1[i][mat[i][j]] = true;
				c2[j][mat[i][j]] = true;
				c3[square(i, j)][mat[i][j]] = true;
			}
			else arr[cnt++] = { i, j };		
		}
	}

	sudoku(0);
	

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << mat[i][j] << ' ';
		}
		cout << '\n';
	}


	return 0;
}