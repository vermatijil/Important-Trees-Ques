#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans=ans+(solve(i-1,dp)*solve(n-i,dp);
    }
    dp[n] = ans;
    return ans;
}

int FindNumberUnique(int n)
{
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << FindNumberUnique(n);
        cout << endl;
    }
    return 0;
}