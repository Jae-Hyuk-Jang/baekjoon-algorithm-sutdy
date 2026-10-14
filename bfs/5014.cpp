#include<bits/stdc++.h>
using namespace std;

int F, S, G, U, D;
const int MX = 10000001;
int path[MX];
bool processed[MX];
vector<int> dx;
queue<int> q;

void bfs(int v) {
	processed[v] = true;
	q.push(v);

	while (!q.empty()) {
		v = q.front();
		q.pop();

		for (int i = 0; i < 2; i++) {
			int nv = v + dx[i];

			if (0 < nv && nv <= F && !processed[nv]) {
				processed[nv] = true;
				q.push(nv);
				path[nv] = path[v] + 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> F >> S >> G >> U >> D;

	dx.push_back(U);
	dx.push_back(D * -1);

	bfs(S);

	if (processed[G]) cout << path[G];
	else cout << "use the stairs";

	return 0;
}