#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;

string plused(string a, string b) {
    string temp = "";
    int digitUp = 0;
    while(a.size() != b.size()) {
        if(a.size() < b.size()) a = '0' + a;
        else b = '0' + b;
    }

    for (int i = a.size() - 1, k; i >= 0; i--) {
        k = (a[i] - '0') + (b[i] - '0') + digitUp;
        if(k >= 10) {
            digitUp = 1;
            k -= 10;
        } else digitUp = 0;
        temp = char(k + '0') + temp;
    }
    if(digitUp == 1) temp = '1' + temp;
    return temp;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    cout << plused(a, b);


    return 0;
}