#include<bits/stdc++.h>
#define MX 210
#define INF 1e9
using namespace std;

int N, M, K;
int mat[MX][MX];
int lived[MX];
int a, b, t;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	
	cin >> N >> M;

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			if (i == j)mat[i][j] = 0;
			else mat[i][j] = INF;
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> a >> b >> t;
		mat[a][b] = t;
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> lived[i];
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
			}
		}
	}

	int answer =INF;
	vector<int> ans;
	for (int i = 1; i<= N; i++) {
		int temp = 0;
		for (int j = 0; j < K; j++) {
			if (mat[i][lived[j]] != INF && mat[lived[j]][i] != INF) {
				temp = max(temp, mat[i][lived[j]] + mat[lived[j]][i]);
			}
		}
		if (answer > temp) {
			ans.clear();
			ans.push_back(i);
			answer = temp;
		}
		else if (answer == temp) {
			ans.push_back(i);
		}
	}

	for (const auto& a : ans) cout << a << ' ';

	return 0;
}