#include<bits/stdc++.h>
#define MX 500001
#define INF 1e9
#define value first
#define index second
using namespace std;

typedef pair<int, int> pii;

int N;
stack<pii> st;
int ans[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	st.push({ INF, 0 });
	int num, idx =1;
	for (int i = 0; i < N; i++) {
		cin >> num;

		while (st.top().value < num) st.pop();

		ans[i] = st.top().index;
		st.push({ num, idx++ });
	}

	for (int i = 0; i < N; i++) cout << ans[i] << ' ';


	return 0;
}