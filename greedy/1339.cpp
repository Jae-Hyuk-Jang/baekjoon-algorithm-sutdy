#include<bits/stdc++.h>
using namespace std;

int graph[26];

bool cmp(int& a, int& b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string input; cin >> input;
		int pow = 1;
		for (int j = input.length() - 1; j >= 0; j--) {
			graph[input[j] - 'A'] += pow;
			pow *= 10;
		}
	}

	sort(graph, graph + 26, cmp);

	int num = 9;
	int answer = 0;
	for (int i = 0; i < 26; i++) {
		if (graph[i] == 0) break;
		answer += graph[i] * (num--);
	}
	cout << answer;
	
	return 0;
}