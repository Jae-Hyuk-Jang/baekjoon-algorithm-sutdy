#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

#define X first
#define Y second

pii philoWalk(int side, int walk) {
	if (side == 2) {
		if (walk == 1) return { 1, 1 };
		else if (walk == 2) return { 1, 2 };
		else if (walk == 3) return { 2, 2 };
		else return { 2, 1 };
	}

	int half = side >> 1;
	int section = half * half;

	if (walk <= section) {
		pii ret = philoWalk(half, walk);
		return { ret.Y, ret.X };
	}
	else if (walk <= 2 * section) {
		pii ret = philoWalk(half, walk - section);
		return { ret.X, ret.Y + half };
	}
	else if (walk <= 3 * section) {
		pii ret = philoWalk(half, walk - 2 * section);
		return { ret.X + half, ret.Y + half };
	}
	else {
		pii ret = philoWalk(half, walk - 3 * section);
		return { 2 * half - ret.Y + 1, half - ret.X + 1 };
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int side, walk;
	cin >> side >> walk;
	pii ans = philoWalk(side, walk);
	cout << ans.X << ' ' << ans.Y;

	return 0;
}