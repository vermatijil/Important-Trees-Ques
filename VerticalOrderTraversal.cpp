#include <iostream>
#include <vector>
#include "TakeInput.cpp"
#include <map>
#include <queue>
#include <set>

using namespace std;

vector<vector<int>> VerticalOrder(TreeNode *root)
{
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode *, pair<int, int>>> todo;
    todo.push({root, {0, 0}});
    while (!todo.empty())
    {
        auto p = todo.front();
        todo.pop();
        TreeNode *node = p.first;
        int x = p.second.first;
        int y = p.second.second;
        nodes[x][y].insert(node->val);
        if (node->left)
        {
            todo.push({node->left, {x + 1, y + 1}});
        }
        if (node->right)
        {
            todo.push({node->left, {x - 1, y - 1}});
        }
    }
    vector<vector<int>> ans;
    for (auto p : nodes)
    {
        vector<int> col;
        for (auto q : p.second)
        {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
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
        vector<vector<int>> ans = VerticalOrder(root);
        cout << endl;
    }
    return 0;
}