#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0);
using namespace std;

using pii = pair<int, int>;

int N, M, K;
int ans;

int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

struct Ball {
	int r, c, m, s, d;
};

vector<Ball> ball;
vector<Ball> mat[55][55];

void init() {
	for (int i = 0; i < 55; i++) {
		for (int j = 0; j < 55; j++) {
			mat[i][j].clear();
		}
	}
}

void move() {
	init();
	for (int i = 0; i < ball.size(); i++) {
		Ball tmp;
		int ny = ball[i].r + dy[ball[i].d] * ball[i].s;
		int nx = ball[i].c + dx[ball[i].d] * ball[i].s;
		if (0 < ny) {
			tmp.r = ny % N;
			if (tmp.r == 0) tmp.r = N;
		}
		else tmp.r = N + ny % N;

		if (0 < nx) {
			tmp.c = nx % N;
			if (tmp.c == 0) tmp.c = N;
		}
		else tmp.c = N + nx % N;

		tmp.m = ball[i].m, tmp.s = ball[i].s, tmp.d = ball[i].d;
		mat[tmp.r][tmp.c].push_back(tmp);
	}
	ball.clear();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!mat[i][j].empty()) {
				if (mat[i][j].size() <= 1) ball.push_back(mat[i][j][0]);
				else {
					Ball tmp; tmp.r = i, tmp.c = j;
					tmp.m = 0, tmp.s = 0, tmp.d = 0;
					bool dir = true;

					for (const auto& iter : mat[i][j]) {
						tmp.m += iter.m;
						tmp.s += iter.s;
						if (mat[i][j][0].d % 2 != iter.d % 2) dir = false;
					}

					if (tmp.m < 5) continue;
					tmp.m = int(tmp.m / 5);
					tmp.s = int(tmp.s / mat[i][j].size());

					if (dir) {
						for (int i = 0; i < 8; i += 2) {
							tmp.d = i; ball.push_back(tmp);
						}
					}
					else {
						for (int i = 1; i < 8; i += 2) {
							tmp.d = i; ball.push_back(tmp);
						}
					}
				}
			}
		}
	}
}

int main() {
	fastio();

	cin >> N >> M >> K;
	ball = vector<Ball>(M);
	for (int i = 0; i < M; i++) {
		cin >> ball[i].r >> ball[i].c >> ball[i].m >> ball[i].s >> ball[i].d;
	}

	while (K--) move();
	for (const auto& b : ball) ans += b.m;
	cout << ans;

	return 0;
}