#include <iostream>
#include <vector>
using namespace std;

int N;
int map[101][101];

int dr[] = {1, 0, -1, 0};
int dc[] = {0, -1, 0, 1};
int mx, my, sx, sy;
int ans;

void check_point(int x, int y, vector<int> point){
    for(int i=0;i<point.size();i++){
        int nx = x+dr[point[i]];
        int ny = y+dc[point[i]];
        if(mx<nx) mx=nx;
        if(my<ny) my=ny;
        if(sx>nx) sx=nx;
        if(sy>ny) sy=ny;
        map[nx][ny] = 1;
        x = nx; y = ny;
    }
}

void run(){
    for(int i=sx;i<=mx;i++){
        for(int j=sy;j<=my;j++){
            if(map[i][j] == 1 && map[i+1][j] == 1 && map[i][j+1] == 1 && map[i+1][j+1] == 1) ans += 1;
        }
    }
}

void simulation(int x, int y, int dir, int stage){
    vector<int> v;
    v.push_back(dir);
    if(stage>=1) v.push_back((dir+1)%4);
    for(int i=1;i<stage;i++){
        int n = 1;
        for(int j=0;j<i;j++){
            n *= 2;
        }
        int m = 1;
        for(int j=1;j<i;j++){
            m *= 2;
        }
        for(int j=0;j<n;j++){
            if(j<m){
                v.push_back((v[j]+2)%4);
            }
            else{
                v.push_back(v[j]);
            }
        }
    }
    map[x][y] = 1;
    check_point(x, y, v);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++){
        int x, y, dir, stage;
        cin>>x>>y>>dir>>stage;
        simulation(x, y, dir, stage);
    }
    ans = 0;
    run();
    cout<<ans;
    return 0;
}

