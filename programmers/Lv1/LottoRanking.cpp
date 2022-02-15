#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
#define SELECTED_COUNT 6
#define LOTTO_COUNT 46

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int count[LOTTO_COUNT] = {0,};
    int i = 0;
    int commonCnt = 0;
    int zeroCnt = 0;

    for (i = 0; i < SELECTED_COUNT; ++i)
    {
        count[lottos[i]]++;
        count[win_nums[i]]++;
    }
    for (i = 0; i < LOTTO_COUNT; ++i)
    {
        if (0 == i) zeroCnt += count[i];
        else if (2 == count[i]) commonCnt++;
    }

    vector<int> answer;
    answer.push_back(min(7 - commonCnt - zeroCnt, 6)); // best
    answer.push_back(min(7 - commonCnt, 6)); // worst

    return answer;
}