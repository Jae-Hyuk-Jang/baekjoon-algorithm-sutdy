#include<iostream>
#include<algorithm>
#include<stack>
#define MX 1000004

using namespace std;
using pii = pair<int,int>;

int n, lis[MX], len, num;
pii ans[MX];
stack<int> st;

const int INF = 1e9 + 4;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fill(lis, lis + MX, INF);
    cin >> n;
    for(int i =0; i< n; i++) {
        cin >> num;
        auto lowerPos = lower_bound(lis, lis + len, num);
        int _pos = (int)(lower_bound(lis, lis + len, num) - lis);
        if(*lowerPos == INF) len++;
        *lowerPos = num;
        ans[i].first = _pos; ans[i].second = num;
    }
    cout << len << '\n';
    for(int i = n - 1; i >= 0; i--) {
        if (ans[i].first == len - 1) {
            st.push(ans[i].second); len--;
        }
    }

    while(st.size()) { cout << st.top() << '\n'; st.pop(); }
   
    return 0;
}