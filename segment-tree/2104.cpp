#include<bits/stdc++.h>
#define MX 100001
using namespace std;
typedef long long ll;

int N;
ll arr[MX];

ll solve(int start, int end) {
	if (start == end) return arr[start] * arr[start];
	int mid = (start + end) / 2;
	ll resLeft = solve(start, mid);
	ll resRight = solve(mid + 1, end);
	
	ll result = max(resLeft, resRight);

	int left = mid;
	int right = mid + 1;

	ll minValue = min(arr[left], arr[right]);

	ll sum = arr[left] + arr[right];
	result = max(result, minValue * sum);

	while (left > start || right < end) {
		if (right < end && (start == left || arr[left - 1] < arr[right + 1])) {
			right++;
			sum += arr[right];
			minValue = min(minValue, arr[right]);
		}
		else {
			left--;
			sum += arr[left];
			minValue = min(minValue, arr[left]);
		}
		result = max(result, minValue * sum);
	}
	return result;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	cout << solve(1, N);


	return 0;
}