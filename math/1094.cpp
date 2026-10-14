#include<iostream>
#include<algorithm>

using namespace std;

int n, ret = 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n != 1) {
        if(n &1) ret++;
        n >>= 1;
    }
    cout << ret;

    return 0;
}