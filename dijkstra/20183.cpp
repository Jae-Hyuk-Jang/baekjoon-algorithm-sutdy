#include<bits/stdc++.h>

#define MX 100001
#define LL long long
#define INF 1e15

using namespace std;

LL N, M, A, B, C;
vector<pair<LL, LL> > Edge[MX];
LL Cost[MX];
LL answer = INF;
priority_queue<pair<LL, LL>> PQ;


void Dijkstra(LL X) {
	Cost[A] = 0;
	PQ.push({ 0, A });

	while (!PQ.empty()) {
		LL CurC = -PQ.top().first;
		LL CurX = PQ.top().second;
		PQ.pop();

		if (Cost[CurX] < CurC) continue;

		for (auto& n : Edge[CurX]) {
			LL nextC = n.second;
			LL nextX = n.first;

			if (nextC > X) continue;

			if ((CurC + nextC <= C) && (Cost[nextX] > CurC + nextC)) {
				Cost[nextX] = CurC + nextC;
				PQ.push({ -Cost[nextX], nextX });
			}
		}
	};
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	cin >> N >> M >> A >> B >> C;
	for (LL i = 0; i < M; i++) {
		LL U, V, W;
		cin >> U >> V >> W;
		Edge[U].push_back(make_pair(V, W));
		Edge[V].push_back(make_pair(U, W));
	}


	LL LO = 1;
	LL HI = C;

	while (LO <= HI) {
		LL MID = (LO + HI) / 2;

		for (LL i = 1; i <= N; i++) Cost[i] = INF;

		Dijkstra(MID);

		if (Cost[B] != INF) {
			answer = MID;
			HI = MID - 1;
		}
		else {
			LO = MID + 1;
		}
	};


	cout << ((answer == INF) ? -1 : answer);

	return 0;
}