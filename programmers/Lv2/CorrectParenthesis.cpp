#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    char stack[100000];
    int index = 0;
    
    // optimization
    if (s[0] == ')' || s[s.size() - 1] == '(' || s.size() % 2 != 0) return false;
    
    for (int i = 0; i < s.size(); i++) {
        if (index == 0) stack[index++] = s[i];
        else if (stack[index - 1] == '(' && s[i] == ')') index--;
        else if (stack[index - 1] == '(' && s[i] == '(') stack[index++] = s[i];
    }
    
    if (index != 0) return false;
    else return true;
}