#include<bits/stdc++.h>
#define MX 1000001
using namespace std;
using ll = long long;

int arr[MX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, mx =-1;
    ll st, en, mid, sum;

    cin >> n >> m;
    for(int i = 0; i< n; i++) cin >> arr[i];
    sort(arr, arr+n);
    st = 0, en = arr[n-1];

    while(st <= en) {
        sum = 0;
        mid = (st+ en) / 2;
        for(int i =0; i< n; i++) {
            if(arr[i] - mid > 0) sum += arr[i] - mid;
        }

        if(sum >= m) {
            st = mid + 1;
            if(mid > mx) mx = mid;
        }
        else en = mid -1;
    }
    cout << mx;

    return 0;
}