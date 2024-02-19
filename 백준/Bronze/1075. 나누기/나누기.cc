#include <iostream>
using namespace std;
long long N;
int F, ans, val;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>N>>F;
    val = N/100;
    for(int i=0;i<100;i++){
        long long M = val*100+i;
        if(M%F == 0){
            ans = M%100;
            break;
        }
    }
    if(ans<10) cout<<"0";
    cout<<ans;

    return 0;
}