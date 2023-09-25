#include <iostream>
#include <vector>
#include "TakeInput.cpp"

using namespace std;

// this is the another way of solving this question
// returning the diameter and height as the pair from the root to decrease the time complexity
pair<int, int> DiameterBinaryTreeSecond(TreeNode *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> left = DiameterBinaryTreeSecond(root->left);
    pair<int, int> right = DiameterBinaryTreeSecond(root->left);
    int rh = right.first;
    int rd = right.second;
    int lh = left.first;
    int ld = left.second;
    int height = 1 + max(lh, rh);
    int d = max((lh + rh), max(ld, rd));
    pair<int, int> p;
    p.first = height;
    p.second = d;
    return p;
}

int height(TreeNode *root)
{
    if (root == NULL)
        return true;
    return max(height(root->right), height(root->left)) + 1;
}

int DiameterBinaryTree(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int option1 = height(root->left) + height(root->right);
    int option2 = DiameterBinaryTree(root->right);
    int option3 = DiameterBinaryTree(root->left);

    return max(option1, max(option2, option3));
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        TreeNode *root = TakeInputTree();
        cout << DiameterBinaryTree(root);
        cout << endl;
    }
    return 0;
}
