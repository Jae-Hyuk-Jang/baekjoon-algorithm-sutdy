#include<bits/stdc++.h>
#define MX 100001
using namespace std;

typedef pair<int, int> pii;

int N;
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int s, e; cin >> s >> e;
		pq.push({ e, s });
	}
	
	int start, end; 
	int before_end = pq.top().first;
	pq.pop();

	int cnt = 1;
	while (!pq.empty()) {
		start = pq.top().second;
		end = pq.top().first;
		/*cout << "pq pop >> " << start << ' ' << end << '\n';*/
		pq.pop();

		/*cout << before_end << '\n';*/

		if (before_end <= start) {
			cnt++;
			before_end = end;
			/*cout << before_end << '\n';
			cout << start << ' ' << end << '\n';*/
		}

	}
	cout << cnt;
	return 0;
}