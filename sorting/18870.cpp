#include<bits/stdc++.h>
#define MX 1000001
using namespace std;


int ans[MX];
pair<int, int> arr[MX];
int N;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	int num = 0;
	for (int i = 0; i < N; i++) {
		cin >> num;
		arr[i] = { num, i };
	}
	sort(arr, arr + N);

	
	ans[arr[0].second] = 0;
	for (int i = 1; i < N; i++) {
		if (arr[i - 1].first == arr[i].first) ans[arr[i].second] = ans[arr[i - 1].second];
		else ans[arr[i].second] = ans[arr[i - 1].second] + 1;
	}
	for (int i = 0; i < N; i++) {
		cout << ans[i] << ' ';
	}

	return 0;
}