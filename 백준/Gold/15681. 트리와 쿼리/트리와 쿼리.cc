#include <iostream>
#include <vector>
using namespace std;

int N, R, Q;
vector<int> v[100001];
int check[100001] = {0,};
int visited[100001] = {0,};

int dfs(int now){
    //check[now] = 1;
    //if(v[now].size() == 1) return 1;
    if(check[now] != 0) return check[now];
    check[now] = 1;
    visited[now] = 1;
    for(int i=0;i<v[now].size();i++){
        if(visited[v[now][i]] == 1) continue;
        //visited[v[now][i]] = 1;
        check[now] += dfs(v[now][i]);
    }
    return check[now];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>N>>R>>Q;
    for(int i=0;i<N-1;i++){
        int to, from; cin>>to>>from;
        v[to].push_back(from);
        v[from].push_back(to);
    }
    check[R] = dfs(R);
    
    for(int i=0;i<Q;i++){
        int num; cin>>num;
        cout<<check[num]<<"\n";
    }
    return 0;
}