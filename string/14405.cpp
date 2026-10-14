#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str; cin >> str;
    int n = str.length();

    bool flag = true;

    for (int i = 0; i < n; i++) {
        if(i < n - 1 && str.substr(i, 2) == "pi" || str.substr(i,2) == "ka") i++;
        else if (i < n - 2 && str.substr(i, 3) == "chu") i += 2;
        else flag = false;
    }

    cout << ((flag) ? "YES" : "NO") << '\n';

    return 0;
}