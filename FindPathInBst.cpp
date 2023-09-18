#include <iostream>
#include <vector>
#include "TakeInput.cpp"

using namespace std;

vector<int> *findpath(TreeNode *root, int k)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->val == k)
    {
        vector<int> *ans = new vector<int>();
        ans->push_back(root->val);
        return ans;
    }
    vector<int> *right = findpath(root->right, k);
    if (right != NULL)
    {
        right->push_back(root->val);
        return right;
    }
    vector<int> *left = findpath(root->left, k);
    if (left != NULL)
    {
        left->push_back(root->val);
        return left;
    }
    return NULL;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        TreeNode *root = TakeInputTree();
        int k;
        cin >> k;
        vector<int> *ans = findpath(root, k);
        for (int i = 0; i < ans->size(); i++)
        {
            cout << ans->at(i) << " ";
        }
    }
    return 0;
}