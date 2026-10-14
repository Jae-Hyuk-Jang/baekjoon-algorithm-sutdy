#include<bits/stdc++.h>
#define MX 500000
using namespace std;
typedef pair<int, int> pii;

int sis, bro;
int board[MX + 2];
int processed[2][MX + 2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> sis >> bro;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0, sis });
	int ans = 0;

	for (int i = 0; i < 2; i++)
		fill(processed[i], processed[i] + MX + 2, -1);
	processed[0][sis] = 0;

	while (!pq.empty()) {
		int time= pq.top().first; 
		int x = pq.top().second;
		pq.pop();
		int ntime = time + 1;

		

		for (const auto nv : { x - 1, x + 1, x * 2 }) {
			if (nv < 0 || nv > 500000) continue;
			if (processed[ntime % 2][nv] != -1) continue;
			processed[ntime % 2][nv] = ntime;
			pq.push({ ntime, nv });
		}
	}

	bool found = false;
	while (bro <= MX) {
		if (processed[ans % 2][bro] <= ans) {
			found = true;
			break;
		}
		bro += (++ans);
	}
	cout << ((found) ? ans : -1) << '\n';
	return 0;
}