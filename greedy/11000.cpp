#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int N;
pii lecture[200002];
priority_queue<int, vector<int>, greater<>> pq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		lecture[i] = { a, b };
	}
	sort(lecture, lecture + N);

	pq.push(0);
	
	for (int i = 0; i < N; i++) {
		int s, e; tie(s, e) = lecture[i];
		int c = pq.top(); pq.pop();
		pq.push(e);

		if (s < c) pq.push(c);
	}
	cout << pq.size();
	return 0;
}