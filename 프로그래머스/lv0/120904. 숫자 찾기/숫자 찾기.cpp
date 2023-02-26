#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int num, int k) {
    int answer = 0;
    int cnt = 0, step = 0;
    while(1){
        cnt++;
        if(num%10 == k){
            step = cnt;
        }
        num /= 10;
        if(num == 0) break;
    }
    if(step == 0) answer = -1;
    else answer = cnt-step+1;
    return answer;
}