#include <string>
#include <vector>
#include <cctype>
#include <iostream>
#include <cmath>

using namespace std;

int solution(string s) {
    int arr[10] = {-1,};
    int i, index = 0, answer = 0;
    
    for (i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i])) arr[index++] = s[i] - '0';
        if (s[i] == 'o')
        {
            arr[index++] = 1;
            i += 2;
        }
        else if (s[i] == 't' && s[i+1] == 'w')
        {
            arr[index++] = 2;
            i += 2;
        }
        else if (s[i] == 't' && s[i+1] == 'h')
        {
            arr[index++] = 3;
            i += 4;
        }
        else if (s[i] == 'f' && s[i+1] == 'o')
        {
            arr[index++] = 4;
            i += 3;
        }
        else if (s[i] == 'f' && s[i+1] == 'i')
        {
            arr[index++] = 5;
            i += 3;
        }
        else if (s[i] == 's' && s[i+1] == 'i')
        {
            arr[index++] = 6;
            i += 2;
        }
        else if (s[i] == 's' && s[i+1] == 'e')
        {
            arr[index++] = 7;
            i += 4;
        }
        else if (s[i] == 'e')
        {
            arr[index++] = 8;
            i += 4;
        }
        else if (s[i] == 'n')
        {
            arr[index++] = 9;
            i += 3;
        }
        else if (s[i] == 'z')
        {
            arr[index++] = 0;
            i += 3;
        }
    }

    for (int i = 0, j = index - 1; i < index; i++, j--)
    {
        answer += arr[i] * pow(10, j);
    }
    return answer;
}