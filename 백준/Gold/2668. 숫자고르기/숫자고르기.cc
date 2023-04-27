#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int arr[101];
int check[101] = {0,};
vector<int> v;

void dfs(int now, int cnt, int st){
    if(cnt == N) return;
    if(now == st){
        v.push_back(st);
        return;
    }
    if(check[now] == 0){
        check[now] = 1;
        dfs(arr[now], cnt+1, st);
        check[now] = 0;
    }
}

int main(){
    cin>>N;
    for(int i=1;i<=N;i++){
        int num; cin>>num;
        arr[i] = num;
    }
    for(int i=1;i<=N;i++){
        if(check[i] == 0){
            check[i] = 1;
            dfs(arr[i], 1, i);
            check[i] = 0;
        }
    }
    cout<<v.size()<<"\n";
    sort(v.begin(), v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<"\n";
    }
    return 0;
}