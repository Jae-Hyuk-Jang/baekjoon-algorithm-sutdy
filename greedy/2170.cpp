#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define MX 1000001

int N;
vector<pair<int, int>> vec;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b; cin >> a >> b;
		vec.push_back({ a, b });
	}
	sort(vec.begin(), vec.end());

	int st = vec[0].x;
	int en = vec[0].y;

	int dist = 0;
	for (int i = 1; i < N; i++) {
		int nx = vec[i].x;
		int ny = vec[i].y;

		if (en < nx) {
			dist += (en - st);
			st = nx, en = ny;
		}
		else en = max(en, ny);
	}
	dist += (en - st);
	cout << dist;

	return 0;
}