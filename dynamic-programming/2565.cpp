#include<bits/stdc++.h>
using namespace std; 

#define MX 101

int arr[MX], acc[MX];
int N;
int a, b;
vector<pair<int, int>> vec;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		vec.push_back({ a, b });
	}
	sort(vec.begin(), vec.end());

	for (int i = 0; i < N; i++) arr[i] = vec[i].second;
	
	int ans = 0;
	for (int i = 0; i < N; i++) {
		acc[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) acc[i] = max(acc[i], acc[j] + 1);
		}
		ans = max(ans, acc[i]);
	}
	cout << N - ans;
	
	return 0;
}