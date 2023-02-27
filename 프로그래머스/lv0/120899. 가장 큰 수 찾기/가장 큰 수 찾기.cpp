#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array) {
    vector<int> answer;
    int maxx=-1, idx = -1;
    for(int i=0;i<array.size();i++){
        if(maxx<array[i]){
            maxx = array[i];
            idx = i;
        }
    }
    answer.push_back(maxx);
    answer.push_back(idx);
    return answer;
}