#include<iostream>
#include<string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s, t; cin >> s >> t;
    string ret;
    for(char a : s) {
        ret += a;
        if(ret.size() >= t.size() && ret.substr(ret.size() - t.size(), t.size()) == t) {
            ret.erase(ret.end() - t.size(), ret.end());
        }
    }

    cout << ((!ret.size()) ? "FRULA" : ret);

    return 0;
}