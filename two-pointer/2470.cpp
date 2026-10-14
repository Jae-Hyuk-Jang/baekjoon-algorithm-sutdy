#include<bits/stdc++.h>
#define MX 100001
#define INF 2000000001
using namespace std;

int arr[MX];
int answer[2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    for(int i=0; i< N; i++) cin >> arr[i];
    sort(arr, arr + N);

    int st = 0, en = N - 1;
    int mn  = INF;
    while(st < en) {
        int sum = arr[st] + arr[en];

        if(mn > abs(sum)) {
            mn = abs(sum);
            answer[0] = arr[st];
            answer[1] = arr[en];

            if(sum == 0) break;
        }

        if(sum < 0) st++;
        else en--;
    }
    sort(answer, answer+2);
    cout << answer[0] << " " << answer[1];

    return 0;
}