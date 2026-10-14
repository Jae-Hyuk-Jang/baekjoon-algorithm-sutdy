#include<iostream>
#include<algorithm>
using namespace std;

int n, m, k;
int l, r;
int dist = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    l = 1, r = m;
    cin >> k;
    for(int i = 0; i< k; i++) {
        int goal; cin >> goal;
         if (goal < l) {
            int delta = l - goal;
            dist += delta;
            l = goal; r = l + m - 1;
        } 
        else if (goal > r) {
            int delta = goal - r;
            dist += delta;
            r = goal; l = r - m + 1;
        }
        else continue;
    }
    cout << dist;
    return 0;
}
