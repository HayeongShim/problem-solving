#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int newComp = 0;
    
    sort(scoville.begin(), scoville.end());
    
    while (scoville[0] < K && scoville.size() > 1) {
        newComp = scoville[0] + scoville[1] * 2;
        scoville[1] = newComp;
        
        scoville.erase(scoville.begin());
        
        sort(scoville.begin(), scoville.end());
        answer++;
    }

    if (scoville.size() == 1 && scoville[0] < K) answer = -1;
    
    return answer;
}
