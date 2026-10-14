#include<bits/stdc++.h>
using namespace std;

#define MX 1001

queue<tuple<int,int,int>> q;
bool processed[MX][MX];
int s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	q.push({ 0, 1, 0 });
	processed[1][0] = 1;
	while (!q.empty()) {
		int time, screen, clip;
		tie(time, screen, clip) = q.front(); q.pop();
		if (screen == s) {
			cout << time;
			return 0;
		}

		if (!processed[screen][screen]) {
			q.push({ time + 1, screen, screen });
			processed[screen][screen] = 1;
		}

		if (screen + clip <= s && !processed[screen + clip][clip]) {
			q.push({ time + 1, screen + clip, clip });
			processed[screen + clip][clip] = 1;
		}

		if (screen - 1 >= 0 && !processed[screen - 1][clip]) {
			q.push({ time + 1, screen - 1, clip });
			processed[screen -1][clip] = 1;
		}
	}

	return 0;
}