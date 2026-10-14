#include<bits/stdc++.h>
#define MX 100
using namespace std;

int N, M, bound;
vector<int> large[MX], light[MX];
int large_cnt[MX], light_cnt[MX];
bool processed[MX];
set<int> s;


void dfs1(int start, int idx) {
	for (auto& next : large[idx]) {
		if (processed[next]) continue;
		processed[next] = true;
		large_cnt[start]++;
		dfs1(start, next);
	}
}

void dfs2(int start, int idx) {
	for (auto& next : light[idx]) {
		if (processed[next]) continue;
		processed[next] = true;
		light_cnt[start]++;
		dfs2(start, next);
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		large[a].push_back(b);
		light[b].push_back(a);
	}

	bound = (N+1) / 2;

	for (int i = 1; i <= N; i++) {
		fill(processed, processed + N + 1, false);
		processed[i] = true;
		dfs1(i, i);
		fill(processed, processed + N + 1, false);
		processed[i] = true;
		dfs2(i, i);
		if (large_cnt[i] >= bound || light_cnt[i] >= bound) s.insert(i);
	}


	cout << s.size();
	return 0;
}