#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int n; 
string str;
vector<int> num;
vector<char> oper_str;
int ret = -1e7;

int oper(char a, int b, int c) {
    if(a == '+') return b + c;
    if (a == '-') return b - c;
    if (a == '*') return b * c;
}

void go(int here, int _num) {
    if (here == num.size() - 1) {
        ret = max(ret, _num);
        return;
    }

    go(here + 1, oper(oper_str[here], _num, num[here + 1]));
    if(here + 2 <= num.size() - 1) {
        int temp = oper(oper_str[here + 1], num[here + 1], num[here + 2]);
        go(here + 2, oper(oper_str[here], _num, temp));
    }
    return;
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> str;
    for(int i = 0; i < n; i++) {
        if(i % 2==0) num.push_back(str[i] - '0');
        else oper_str.push_back(str[i]);
    }

    go(0, num[0]);

    cout << ret;




    return 0;
}