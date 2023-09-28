#include <iostream>
#include <vector>
#include "TakeInput.cpp"
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> ZigZagTraversal(TreeNode *root)
{
    if (root == NULL)
        return {};
    vector<int> temp;
    vector<vector<int>> finalAns;
    queue<TreeNode *> pendingNodes;
    pendingNodes.push(root);
    int k = 0;
    while (pendingNodes.size() != 0)
    {
        int size = pendingNodes.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *front = pendingNodes.front();
            pendingNodes.pop();
            temp.push_back(front->val);
            if (front->left)
                pendingNodes.push(front->left);
            if (front->right)
                pendingNodes.push(front->right);
        }
        k = k + 1;
        if (k % 2 == 0)
        {
            reverse(temp.begin(), temp.end());
            finalAns.push_back(temp);
        }
        else
        {
            finalAns.push_back(temp);
        }
        temp.clear();
    }
    return finalAns;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        TreeNode *root = TakeInputTree();
        vector<vector<int>> finalans = ZigZagTraversal(root);
        for (int i = 0; i < finalans.size(); i++)
        {
            for (int j = 0; j < finalans[i].size(); j++)
            {
                cout << finalans[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
