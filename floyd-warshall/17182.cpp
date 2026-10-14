#include<bits/stdc++.h>
#define MX 210
#define INF 1e9
using namespace std;

int N, S;
int graph[11][11];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i != j) {
				graph[i][j] = INF;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			graph[i][j] = temp;
		}
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	vector<int> Arr;
	for (int i = 0; i < N; i++) Arr.push_back(i);

	int result = INF;
	do {
		if (Arr[0] != S)
			continue;
		int temp = 0;
		for (int i = 0; i < Arr.size() - 1; i++)
		{
			int now = Arr[i];
			int next = Arr[i + 1];
			temp += graph[now][next];
		}
		result = min(result, temp);
	} while (next_permutation(Arr.begin(), Arr.end()));

	cout << result << '\n';

	
	return 0;
}
