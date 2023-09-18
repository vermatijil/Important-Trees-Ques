#include <iostream>
#include <vector>
#include <string>

using namespace std;

string reverseWords(string str)
{
    string finalAns;
    string word;
    vector<string> ans;
    stringstream s(str);
    while (s >> word)
    {
        ans.push_back(word);
    }
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        if (i != 0)
        {
            finalAns = finalAns + ans[i] + " ";
        }
        else
        {
            finalAns = finalAns + ans[i];
        }
    }
    return finalAns;
}