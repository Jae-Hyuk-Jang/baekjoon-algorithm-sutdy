#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string s;
bool ok;

bool is_it(char c) {
    if (c == 'a' || c =='e' || c == 'i' || c =='o' || c == 'u') return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(1) {
        getline(cin, s);
        if(s == "end") break;
        int n = s.length();
        
        ok = true;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(is_it(s[i])) cnt++;
             if (i >= 2){
                if (is_it(s[i]) && is_it(s[i-1]) && is_it(s[i-2])) ok = false;
                if (!(is_it(s[i]) || is_it(s[i-1]) || is_it(s[i-2]))) ok = false;
            } 
            if (i >= 1) {
                if(!(s[i-1] != s[i] || (s[i-1] == 'e' && s[i] =='e') || (s[i-1] == 'o' && s[i] =='o'))) ok = false;
            }
        }

        if(ok && cnt >= 1) cout << "<" << s << "> is acceptable." << '\n';
        else cout << "<" << s << "> is not acceptable." << '\n';

    }



    return 0;
}