#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    int biggestNum = arr[arr.size() - 1];
    int multiNum = 0;
    int count = 0;
    
    sort(arr.begin(), arr.end());
    
    while(count != arr.size()) {
        multiNum++;
        count = 0;
        for (int i = 0; i < arr.size(); i++) {
            if ((biggestNum * multiNum) % arr[i] == 0) count++;
        }
    }
    
    int answer = biggestNum * multiNum;
    return answer;
}