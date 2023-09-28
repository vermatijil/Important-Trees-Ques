#include <iostream>
#include <vector>
#include "TakeInput.cpp"

using namespace std;

int maxPathSum(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int maxi = INT_MIN;
    int ans = maxPath(root, maxi);
    return maxi;
}

int maxPath(TreeNode *root, int &maxi)
{
    if (root == NULL)
        return 0;
    int right = max(0, maxPath(root->right, maxi));
    int left = max(0, maxPath(root->left, maxi));
    maxi = max(maxi, right + left + root->val);
    return max(left, right) + root->val;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        TreeNode *root = TakeInputTree();
        cout << maxPathSum(root);
        cout << endl;
    }
    return 0;
}