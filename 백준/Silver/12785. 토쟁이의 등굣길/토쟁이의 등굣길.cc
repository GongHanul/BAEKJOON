#include <iostream>
#define MAX 1000007
using namespace std;

int w, h, x, y;
long long dp[210][210];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>w>>h>>x>>y;
    
    int maxx=x, minx=x, maxy=y, miny=y;
    int nx = w-x+1, ny = h-y+1;
    
    if(x>nx){
        maxx = x; minx = nx;
    }
    else if(x<nx){
        maxx = nx; minx = x;
    }
    if(y>ny){
        maxy = y; miny = ny;
    }
    else if(y<ny){
        maxy = ny; miny = y;
    }
    
    for(int i=1;i<=maxx;i++){
        for(int j=1;j<=maxy;j++){
            if(i == 1 || j == 1) dp[i][j] = 1;
            else{
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MAX;
            }
        }
    }
    
    cout << (dp[nx][ny] * dp[x][y]) % MAX;
    
    return 0;
}