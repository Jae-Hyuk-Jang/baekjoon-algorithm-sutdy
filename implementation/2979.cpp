#include<iostream>
#include<algorithm>
using namespace std;

int arr[110];
int a, b, c;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;
    for(int i = 0; i < 3; i++) {
        int a, b; cin >> a >> b;
        for(int t = a; t < b; t++) arr[t]++;
    }
    int answer = 0;
    for(int i = 1; i <= 100; i++) {
        if(arr[i] == 1) answer += a;
        else if (arr[i] == 2) answer += b*2;
        else if (arr[i] == 3) answer += c*3;
        else continue;
    }
    cout << answer;

    return 0;
}