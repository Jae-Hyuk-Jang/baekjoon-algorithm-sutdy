#include<bits/stdc++.h>
#define MX 555
using namespace std;

int arr[MX];
int degree[MX][MX];

void solution() {
    memset(degree, 0, sizeof degree);
    int n; cin >> n;

    for(int i = 0; i< n; i++) cin >> arr[i];

    for(int i = 0; i< n; i++) {
        for(int j = i + 1; j < n; j++) {
            degree[arr[i]][arr[j]] = 1;
        }
    }

    int m; cin >> m;
    while(m--) {
        int a, b; cin >> a >> b;
        swap(degree[a][b], degree[b][a]);
    }

    for(int i = 0; i< n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(degree[arr[j]][arr[i]]) swap(arr[i], arr[j]);
        }
    }

    for(int i =0; i < n; i++) {
        for(int j = i +1; j < n; j++) {
            if(degree[arr[j]][arr[i]]) {
                cout << "IMPOSSIBLE\n";
                return;
            }
        }
    }

    for(int i = 0; i< n; i++) cout << arr[i] << ' ';
    cout << '\n';
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solution();
    return 0;
}