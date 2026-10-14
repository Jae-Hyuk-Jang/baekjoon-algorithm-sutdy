#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int b = 0;
        for (int k = 5; k <= n; k *= 5) {
            b += n/k;
        }
        cout << b << '\n';
    }


    return 0;
}