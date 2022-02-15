#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string s) {
    int splitCount = 1, dupCount = 0, len = 0, answer = s.size();
    string prevTempStr, curTempStr, resultStr;
    
    for (int i = splitCount; i <= s.size() / 2; i++, splitCount++)
    {
        resultStr = "";
        dupCount = 0;
        prevTempStr = s.substr(0, i);
        
        for (int j = splitCount; j < s.size(); j += splitCount)
        {
            curTempStr = s.substr(j, splitCount);
            if (curTempStr.compare(prevTempStr) == 0) // 중복 문자열 발생
            {
                if (dupCount == 0) dupCount += 2; // 처음인 경우
                else dupCount++; // 이미 dupCount가 존재하는 경우 1씩 증가
            }
            else // 중복 문자열이 아닌 경우
            {
                if (dupCount == 0) resultStr += prevTempStr; // 단순 write
                else
                {
                    resultStr += to_string(dupCount); // 중복된 횟수를 표기하여 write
                    resultStr += prevTempStr;
                    dupCount = 0;
                }
            }
            prevTempStr = curTempStr;
        }
        
        // for문이 끝난 후, 남아있는 문자열을 write
        if (dupCount == 0) resultStr += prevTempStr;
        else
        {
            resultStr += to_string(dupCount);
            resultStr += prevTempStr;
        }
                            
        len = resultStr.size();
        answer = min(len, answer);
    }
    return answer;
}