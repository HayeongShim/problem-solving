#include <string>
#include <vector>
#include <iostream>
#include <cctype>

using namespace std;

string solution(string new_id) {
    int i = 0;
    
    // step 1, 2
    while (i < new_id.size())
    {
        new_id[i] = tolower(new_id[i]);
        if (!islower(new_id[i]) && !isdigit(new_id[i]) &&
            new_id[i] != '-' && new_id[i] != '_' && new_id[i] != '.')
            new_id.erase(i, 1);
        else i++;
    }
    
    // step 3
    i = 0;
    while (i < new_id.size())
    {
        if (new_id[i] == '.' && new_id[i+1] == '.' && (i+1 < new_id.size()))
            new_id.erase(i, 1);
        else i++;
    }
    
    // step 4
    if (new_id.front() == '.') new_id.erase(0, 1);
    if (new_id.back() == '.') new_id.erase(new_id.size() - 1, 1);
    
    // step 5
    if (new_id.empty()) new_id.push_back('a');
    
    // step 6
    if (new_id.size() >= 16)
    {
        new_id.erase(15, new_id.size() - 1);
        if (new_id.back() == '.') new_id.erase(new_id.size() - 1, 1);
    }

    // step 7
    while (new_id.size() <= 2) new_id.push_back(new_id[new_id.size() - 1]);
    
    string answer = new_id;
    return answer;
}