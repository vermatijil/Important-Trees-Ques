#include <iostream>
#include <vector>
#include "TakeInput.cpp"

using namespace std;

int h(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int lefth = h(root->left);
    int righth = h(root->right);
    if (lefth == -1 || righth == -1 || abs(lefth - righth) > 1)
        return -1;
    return max(lefth, righth) + 1;
}

bool Isbalanced(TreeNode *root)
{
    if (root == NULL)
        return true;
    if (h(root) == -1)
        return false;
    return true;
}

// this is the another method

int height(TreeNode *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

bool isBalancedSecond(TreeNode *root)
{
    if (root == NULL)
        return true;
    if (root->right == NULL and root->left == NULL)
        return true;
    if (isBalancedSecond(root->right) == NULL)
        return false;
    if (isBalancedSecond(root->left) == NULL)
        return false;
    if (abs(height(root->right) - height(root->left)) <= 1)
        return true;
    else
        return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        TreeNode *root = TakeInputTree();
        if (Isbalanced(root))
            cout << "true";
        else
            cout << "False";
        cout << endl;
    }
    return 0;
}