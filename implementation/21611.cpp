#include <bits/stdc++.h>
#define MX 55
using namespace std;
using pii = pair<int,int>;

int N, M, Answer, marble[4];
int mat[MX][MX];
int n_mat[MX][MX];

struct coord { int x, y; };
coord shark;
coord Coord[MX*MX];
vector<pii> cmd;

int dx[] = {0,-1,1,0,0}; // 1=상,2=하,3=좌,4=우
int dy[] = {0,0,0,-1,1};

int changeDir(int dir){
    if(dir==1) return 3;
    if(dir==2) return 4;
    if(dir==3) return 2;
    if(dir==4) return 1;
    // If dir is not 1-4, return a default direction (e.g., 3)
    return 3;
}

void input(){
    cin>>N>>M;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>mat[i][j];
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        cmd.push_back({a,b});
    }
}

void make_map(){
    int x=N/2,y=N/2;
    shark={x,y};
    int move_cnt=1,num=0,dir=3;
    n_mat[x][y]=num;
    Coord[num++]={x,y};
    while(1){
        for(int k=0;k<2;k++){
            for(int j=0;j<move_cnt;j++){
                x+=dx[dir], y+=dy[dir];
                n_mat[x][y]=num;
                Coord[num++]={x,y};
            }
            dir=changeDir(dir);
        }
        move_cnt++;
        if(move_cnt==N){
            for(int j=0;j<move_cnt;j++){
                x+=dx[dir], y+=dy[dir];
                n_mat[x][y]=num;
                Coord[num++]={x,y};
            }
            break;
        }
    }
    return;
}

void blizzard(int idx){
    int dir=cmd[idx].first;
    int k=cmd[idx].second;
    int x=shark.x,y=shark.y;
    for(int i=0;i<k;i++){
        x+=dx[dir], y+=dy[dir];
        mat[x][y]=0; 
    }
}

void move_marble(){
    vector<int> v;
    for(int i=1;i<N*N;i++){
        int x=Coord[i].x,y=Coord[i].y;
        if(mat[x][y]!=0) v.push_back(mat[x][y]);
    }
    for(int i=1;i<N*N;i++){
        int x=Coord[i].x,y=Coord[i].y;
        if(i-1<(int)v.size()) mat[x][y]=v[i-1];
        else mat[x][y]=0;
    }
}

bool explode(){
    vector<int> v;
    for(int i=1;i<N*N;i++){
        int x=Coord[i].x,y=Coord[i].y;
        if(mat[x][y]!=0) v.push_back(mat[x][y]);
        else break;
    }
    if(v.empty()) return false;
    vector<int> newv;
    bool exploded=false;
    for(int i=0;i<(int)v.size();){
        int j=i;
        while(j<(int)v.size() && v[i]==v[j]) j++;
        int len=j-i;
        if(len>=4){
            exploded=true;
            marble[v[i]]+=len;
        }else{
            for(int k=i;k<j;k++) newv.push_back(v[i]);
        }
        i=j;
    }
    for(int i=1;i<N*N;i++){
        int x=Coord[i].x,y=Coord[i].y;
        if(i-1<(int)newv.size()) mat[x][y]=newv[i-1];
        else mat[x][y]=0;
    }
    return exploded;
}

void remake(){
    vector<int> v;
    for(int i=1;i<N*N;i++){
        int x=Coord[i].x,y=Coord[i].y;
        if(mat[x][y]!=0) v.push_back(mat[x][y]);
        else break;
    }
    vector<int> newv;
    for(int i=0;i<(int)v.size();){
        int j=i;
        while(j<(int)v.size() && v[i]==v[j]) j++;
        int len=j-i;
        newv.push_back(len);
        newv.push_back(v[i]);
        i=j;
        if((int)newv.size()>=N*N-1) break;
    }
    for(int i=1;i<N*N;i++){
        int x=Coord[i].x,y=Coord[i].y;
        if(i-1<(int)newv.size()) mat[x][y]=newv[i-1];
        else mat[x][y]=0;
    }
}

void solution(){
    make_map();
    for(int i=0;i<M;i++){
        blizzard(i);
        move_marble();
        while(explode()){
            move_marble();
        }
        remake();
    }
    Answer=marble[1]+2*marble[2]+3*marble[3];
    cout<<Answer<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solution();
    return 0;
} 