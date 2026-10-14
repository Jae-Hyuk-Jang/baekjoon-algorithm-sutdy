#include<bits/stdc++.h>
using namespace std;

#define MX 1000001
int arr[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	stack<pair<int,int>> st;
	int N; cin >> N;
	int num;
	fill(arr, arr + N + 1, -1);

	for (int i = 1; i <= N; i++) {
		cin >> num;
		while (!st.empty() && st.top().first < num) {
			arr[st.top().second] = num;
			st.pop();
		}
		st.push({ num, i });
	}

	for (int i = 1; i <= N; i++) cout << arr[i] << ' ';

	return 0;
}