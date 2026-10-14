#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<ll, ll> p;

struct asdf {
	ll node;
	ll cost;
	ll cnt;

	bool operator<(const asdf x) const {
		return cost > x.cost;
	}
};


ll n, m, k;

vector<p> g[10101];
ll dist[10101][22];

void dijkstra() {
	memset(dist, 0x3f, sizeof dist);
	priority_queue<asdf> pq; pq.push({ 1, 0, 0 });
	dist[1][0] = 0;

	while (!pq.empty()) {
		ll now = pq.top().node;
		ll cost = pq.top().cost;
		ll cnt = pq.top().cnt;
		pq.pop();

		if (cost > dist[now][cnt]) continue;
		for (auto i : g[now]) {
			ll nxt = i.first;
			ll nxtCost = cost + i.second;

			if (nxtCost < dist[nxt][cnt]) {
				dist[nxt][cnt] = nxtCost;
				pq.push({ nxt, nxtCost, cnt });
			}
			if (cnt < k && cost < dist[nxt][cnt + 1]) {
				dist[nxt][cnt + 1] = cost;
				pq.push({ nxt, cost, cnt + 1 });
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int s, e, x; cin >> s >> e >> x;
		g[s].push_back({ e, x });
		g[e].push_back({ s, x });
	}

	dijkstra();
	ll ans = 1e18;
	for (int i = 0; i <= k; i++) ans = min(ans, dist[n][i]);
	cout << ans;

	return 0;
}