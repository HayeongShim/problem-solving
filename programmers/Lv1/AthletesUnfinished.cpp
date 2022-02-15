#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, int> mapset;

string solution(vector<string> participant, vector<string> completion) {
    int hashKey, i;
    string answer = "";

    for (i = 0; i < completion.size(); ++i)
    {
        if (mapset.find(completion[i]) != mapset.end()) mapset[completion[i]]++;
        else mapset.insert(make_pair(completion[i], 1));
    }
    
    for (i = 0; i < participant.size(); ++i)
    {
        if (mapset.find(participant[i]) != mapset.end())
        {
            mapset[participant[i]]--;
            if (mapset[participant[i]] < 0) return participant[i];
        }
        else return participant[i];
    }
}