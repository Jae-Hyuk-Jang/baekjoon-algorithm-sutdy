#include<bits/stdc++.h>
using namespace std;
using ld = long double;

struct pos { ld x, y;};

ld xa, ya, xb, yb, xc, yc;

ld ccw(pos a, pos b, pos c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

ld dist(pos a, pos b) {
    ld x = a.x - b.x;
    ld y = a.y - b.y;
    return sqrtl(x * x + y * y);
}

ld get_round(ld a, ld b) { return 2 * (a + b);}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout.precision(14);
    cout << fixed;

    pos a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

    if(ccw(a, b, c) == 0) {cout << -1;}
    else {
        ld ab = dist(a, b);
        ld bc = dist(b, c);
        ld ac = dist(a, c);

        vector<ld> v;
        v.push_back(get_round(ab, ac));
        v.push_back(get_round(ab, bc));
        v.push_back(get_round(ac, bc));

        ld mx = 0, mn = 40000;
        for(const auto& i : v) {
            mx = max(mx, i);
            mn = min(mn, i);
        }
        cout << mx - mn;
    }

    return 0;
}