#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int elem1, elem2, newComp;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }
    
    while (pq.top() < K && pq.size() > 1) {
        elem1 = pq.top(); pq.pop();
        elem2 = pq.top(); pq.pop();
        
        newComp = elem1 + elem2 * 2;
        pq.push(newComp);
        answer++;
    }

    if (pq.size() == 1 && pq.top() < K) answer = -1;
    
    return answer;
}
