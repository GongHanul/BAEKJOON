#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    for(int i=0;i<array.size();i++){
        int num = array[i];
        while(num>0){
            int num_r = num % 10;
            if(num_r == 7) answer++;
            num /= 10;
        }
    }
    return answer;
}