#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include "TakeInput.cpp"

using namespace std;

// everytime left will come first to check for null
vector<int> TopView(TreeNode *root)
{
    if (root == NULL)
        return {};
    vector<int> ans;
    map<int, int> m;
    queue<pair<TreeNode *, int>> pendingNodes;
    pendingNodes.push({root, 0});
    while (pendingNodes.size() != 0)
    {
        auto it = pendingNodes.front();
        pendingNodes.pop();
        TreeNode *node = it.first;
        int line = it.second;
        if (m.find(line) == m.end())
        {
            m[line] = node->val;
        }
        if (node->left)
        {
            pendingNodes.push({node->left, line - 1});
        }
        if (node->right)
        {
            pendingNodes.push({node->right, line + 1});
        }
    }
    for (auto e : m)
    {
        ans.push_back(e.second);
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        TreeNode *root = TakeInputTree();
        vector<int> ans = TopView(root);
        for (auto e : ans)
            cout << e << " ";
        cout << endl;
    }
    return 0;
}