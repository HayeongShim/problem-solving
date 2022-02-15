#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') continue;
        
        if (i == 0 && s[i] >= 65) {
            s[i] = toupper(s[i]);
        }
        else if (i > 0 && s[i-1] == ' ' && s[i] != ' ') {
            s[i] = toupper(s[i]);
        }
        else if (i > 0 && s[i-1] != ' ' && s[i] != ' ') {
            s[i] = tolower(s[i]);
        }
    }
    return s;
}