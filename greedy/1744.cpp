#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll ans;
void acc(vector<int> v) {
	while (1 < v.size()) {
		ans += *(v.end() - 1) * *(v.end() - 2);
		v.pop_back();
		v.pop_back();
	}
	if (v.size()) ans += v[0];
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> seqP, seqN;
	int N, t;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> t;
		if (t == 1)ans++;
		else if (0 < t) seqP.push_back(t);
		else seqN.push_back(t);
	}
	sort(seqP.begin(), seqP.end());
	sort(seqN.begin(), seqN.end(), greater<>());

	acc(seqP);
	acc(seqN);
	cout << ans;
	return 0;
}