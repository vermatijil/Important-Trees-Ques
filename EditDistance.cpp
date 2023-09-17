#include <iostream>
#include <vector>

using namespace std;

int dynmicProgrammingApproach(string s, string t)
{
    int m = s.size();
    int n = t.size();
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size(), -1));
    for (int i = 1; i <= m; i++)
    {
        dp[i][0] = max(s.length(), t.length());
    }
    for (int i = 1; i <= n; i++)
    {
        dp[0][i] = max(s.length(), t.length());
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                int x = dp[i - 1][j - 1] + 1;
                int y = dp[i][j - 1] + 1;
                int z = dp[i][j - 1] + 1;
                dp[i][j] = min(x, min(y, z));
            }
        }
    }
    return dp[m][n];
}

int helper(string s, string t, vector<vector<int>> &dp)
{
    int m = s.size();
    int n = t.size();
    if (s.size() == 0 || t.size() == 0)
    {
        dp[0][0] = max(s.length(), t.length());
        return dp[0][0];
    }
    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }
    int x = helper(s.substr(1), t, dp) + 1;
    int y = helper(s, t.substr(), dp) + 1;
    int z = helper(s.substr(), t.substr(), dp) + 1;
    int ans = min(x, max(y, z));
    dp[m][n] = ans;
    return dp[m][n];
}

int minCount_memo(string s, string t)
{
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size(), -1));
    return helper(s, t, dp);
}

int minCount(string s, string t)
{
    if (s.size() == 0 || t.size() == 0)
    {
        return max(s.length(), t.length());
    }
    if (s[0] == t[0])
    {
        return minCount(s.substr(1), t.substr(1));
    }
    int x = minCount(s.substr(1), t) + 1;
    int y = minCount(s, t.substr()) + 1;
    int z = minCount(s.substr(), t.substr()) + 1;
    int ans = min(x, max(y, z));
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s, t;
        cin >> s >> t;
        cout << minCount(s, t);
        cout << endl;
    }
    return 0;
}