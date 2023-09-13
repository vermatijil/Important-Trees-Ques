#include <iostream>
#include <vector>
#include "TakeInput.cpp"

using namespace std;

vector<TreeNode *> helper(int start, int end)
{
    if (start > end)
    {
        return {nullptr};
    }
    vector<TreeNode *> ans;
    for (int i = start; i <= end; i++)
    {
        vector<TreeNode *> left = helper(start, i - 1);
        vector<TreeNode *> right = helper(i + 1, end);
        for (auto l : left)
        {
            for (auto r : right)
            {
                TreeNode *root = new TreeNode(i);
                root->left = l;
                root->right = r;
                ans.push_back(root);
            }
        }
    }
    return ans;
}

vector<TreeNode *> generateTree(int n)
{
    if (n == 0)
    {
        return {};
    }
    return helper(0, n);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<TreeNode *> ans = generateTree(n);
        for (auto e : ans)
        {
            cout << e->val << " ";
        }
        cout << endl;
    }
    return 0;
}