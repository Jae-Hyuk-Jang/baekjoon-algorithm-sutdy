#include<bits/stdc++.h>
#define MX 1001
using namespace std;
using pii = pair<int,int>;

int a, b, c, d = 0;
int porcessed[MX][MX];


int solve() {
    queue<pii> q;
    q.push({a, b});
    porcessed[a][b] = 1;

    int ca, cb, cc;
    while(!q.empty()) {
        tie(ca, cb) = q.front();
        cc = d - ca - cb;
        q.pop();

        if(ca == cb && ca == cc) return 1;

        int nx[3] = { ca, ca, cb};
        int ny[3] = {cb, cc, cc};

        for(int i= 0; i < 3; i++) {
            int na = nx[i];
            int nb = ny[i];

            if(na < nb) nb -= na, na += na;
            else if(na > nb) na -= nb, nb += nb;
            else continue;

            int nc = d - na - nb;

            int ra = min({na, nb, nc});
            int rb = max({na, nb, nc});

            if(!porcessed[ra][rb]) {
                porcessed[ra][rb] = 1;
                q.push({ra, rb});
            }
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;
    d = a + b + c;

    if((a + b + c) % 3 != 0) cout << 0;
    else cout << solve();

    return 0;
}