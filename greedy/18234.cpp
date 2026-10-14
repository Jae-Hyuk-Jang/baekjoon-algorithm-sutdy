#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, t;
vector<pair<int, int>> vec;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		int w, p; cin >> w >> p;
		vec.push_back({ p, w });
	}
	sort(vec.begin(), vec.end());

	ll answer = 0;
	for (int i = 0; i < n; i++) {
		//cout << vec[i].first << " " << vec[i].second << " " << t - n + 1 + i << endl;
		answer += vec[i].second + vec[i].first *(t - n + i);
	}
	cout << answer;

	return 0;
}