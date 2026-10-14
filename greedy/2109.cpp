#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;
using pii = pair<int,int>;

vector<pii> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i< n; i++) {
        int a, b; cin >> a >> b;
        v.push_back({b, a});
    }
    sort(v.begin(), v.end());
    for (int i =0; i < n; i++) {
        pq.push(v[i].second);
        if(pq.size() > v[i].first) pq.pop();
    }
    int ret = 0;
    while(pq.size()) { ret += pq.top(); pq.pop();}
    cout << ret;

    return 0;
}