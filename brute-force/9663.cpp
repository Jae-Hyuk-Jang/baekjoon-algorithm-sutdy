#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
typedef long long ll;

int N, cnt = 0;
bool isused1[50]; 
bool isused2[50]; 
bool isused3[50]; 

void nqueen(int cur) {
	if (cur == N) {
		cnt++;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (isused1[i] || isused2[i + cur] || isused3[cur -i + N -1]) continue;
		isused1[i] = isused2[i + cur] = isused3[cur - i + N - 1] = 1;
		nqueen(cur + 1);
		isused1[i] = isused2[i + cur] = isused3[cur - i + N - 1] = 0;
	}
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	nqueen(0);
	cout << cnt;

	return 0;
}