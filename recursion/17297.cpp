#include<string>
#include<iostream>

using namespace std;

const int MX = 39;
int f[MX + 1] = {0, 5, 13};
int m;
string s = "Messi Gimossi";

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m; m--;
    for (int i = 3; i <= MX ;i++) {
        f[i] = f[i-1] + f[i-2] + 1;
    }
    for(int i = MX; i >= 2; i--) {
        if(m >= f[i]) m -= (f[i] + 1);
    }
    if(m == 5 || m == -1) cout << "Messi Messi Gimossi" << '\n';
    else cout << s[m] << '\n';
    return 0;
}