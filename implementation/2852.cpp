#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

using pii = pair<int,int>;


static int toSec(const string& s) {
    int mm = stoi(s.substr(0,2));
    int ss = stoi(s.substr(3, 2));
    return mm * 60 + ss;
}

static string toMMSS(int sec) {
    int mm = sec / 60;
    int ss = sec % 60;

    string res;
    res.push_back((mm / 10) + '0');
    res.push_back((mm % 10) + '0');
    res.push_back(':');
    res.push_back((ss / 10) + '0');
    res.push_back((ss % 10) + '0');
    return res;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    vector<pii> events;
    events.reserve(N);

    for (int i = 0; i< N; i++) {
        int team; string t;
        cin >> team >> t;
        events.push_back({toSec(t), team});
    }

    sort(events.begin(), events.end());

    const int END = 48 * 60;

    int score1 = 0, score2 = 0;
    int prev = 0;
    int leadTime1 = 0, leadTime2 = 0;

    auto leader = [&]() -> int {
        if(score1 > score2) return 1;
        if (score2 > score1) return 2;
        return 0;
    };

    for(auto [t, team] : events) {
        int curLeader = leader();
        if (curLeader == 1) leadTime1 += (t -prev);
        else if (curLeader == 2) leadTime2 += (t - prev);

        if(team == 1) score1++;
        else score2++;

        prev = t;
    }

    int curLeader = leader();
    if(curLeader == 1) leadTime1 += (END - prev);
    else if(curLeader == 2) leadTime2 += (END - prev);
    
    cout << toMMSS(leadTime1) << '\n';
    cout << toMMSS(leadTime2) << '\n';

    return 0;
}