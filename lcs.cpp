#include <iostream>
#include <vector>
#include <string>

using namespace std;

int lcs_dynamicProgramming(string s, string t)
{
    int m = s.size();
    int n = t.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[m - i] == t[n - j])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                int a = dp[i - 1][j];
                int b = dp[i][j - 1];
                int c = dp[i - 1][j - 1];
                dp[i][j] = max(a, max(c, b));
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
        return 0;
    }
    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }
    if (s[0] == t[0])
    {
        int ans = 1 + helper(s.substr(1), t.substr(1), dp);
    }
    else
    {
        int a = helper(s.substr(1), t, dp);
        int b = helper(s, t.substr(1), dp);
        int c = helper(s.substr(), t.substr(), dp);
        dp[m][n] = max(a, max(c, b));
    }
    return dp[m][n];
}

int lcsMemo(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return helper(s, t, dp);
}

int lcs(string s, string t)
{
    if (t.size() == 0 || s.size() == 0)
    {
        return 0;
    }
    if (s[0] == t[0])
    {
        return 1 + lcs(s.substr(), t.substr());
    }
    else
    {
        int a = lcs(s.substr(1), t);
        int b = lcs(s, t.substr(1));
        int c = lcs(s.substr(), t.substr());
        return max(a, max(c, b));
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s, t;
        cin >> s >> t;
        cout << lcs(s, t);
        cout << endl;
    }
    return 0;
}