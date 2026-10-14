#include<cstdio>
#include<algorithm>
#include<iostream>

#define MX 404

int n, K, s, e, a, b, c, dist[MX][MX], t;
const int INF = 987654321;

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> K;
    for (int i = 0; i < K; i++) {
        cin >> a >> b; dist[a][b] = -1, dist[b][a] = 1;
    }

    for (int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if(dist[i][k] == 1 && dist[k][j] == 1) dist[i][j] = 1;
                else if (dist[i][k] == -1 && dist[k][j] == -1) dist[i][j] = -1;
            }
        }
    }
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> s >> e; cout << dist[s][e] << '\n';
    }

    return 0;
}