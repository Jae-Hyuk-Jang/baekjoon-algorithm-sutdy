#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m;
    cin >> m;

    int n = 0;

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;

        if (s == "add") {
            int x; cin >> x;
            n |= (1 << x);
        }
        else if (s == "remove") {
            int x; cin >> x;
            n &= ~(1 << x);
        }
        else if (s == "check") {
            int x; cin >> x;
            cout << ((n & (1 << x)) ? 1 : 0) << '\n';
        }
        else if (s == "toggle") {
            int x; cin >> x;
            n ^= (1 << x);
        }
        else if (s == "all") {
            n = (1 << 21) - 1;
        }
        else if (s == "empty") {
            n = 0;
        }
    }

    return 0;
}