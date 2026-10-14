#include<bits/stdc++.h>
#define MX 2001
using namespace std;

int N, M, K;
char board[MX][MX];
int value, pSum[MX][MX];


int play(char color) {
	value = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			pSum[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!((i + j) % 2)) {
				value = (board[i][j] != color);
			}
			else {
				value = (board[i][j] == color);
			}
			pSum[i + 1][j + 1] = pSum[i][j + 1] + pSum[i + 1][j] - pSum[i][j] + value;
		}
	}
	
	int temp, result = 1e9;
	for (int i = 0; i <= N - K; i++) {
		for (int j = 0; j <= M - K; j++) {
			temp = pSum[i + K][j + K] - pSum[i][j + K] - pSum[i + K][j] + pSum[i][j];
			result = min(temp, result);
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	cout << min(play('B'), play('W'));
	return 0;
}