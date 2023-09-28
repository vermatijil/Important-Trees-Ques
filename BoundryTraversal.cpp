#include <iostream>
#include <vector>
#include "TakeInput.cpp"
#include <bits/stdc++.h>

using namespace std;

// this will add the left boundary of the binary tree
void leftBoundary(TreeNode *root, vector<int> &res)
{
    TreeNode *curr = root->left;
    while (curr)
    {
        if (!isLeaf(curr))
            res.push_back(curr->val);
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

// this will add the right boundary of the binary tree
void rightBoundary(TreeNode *root, vector<int> &res)
{
    TreeNode *curr = root->right;
    vector<int> temp;
    while (curr)
    {
        if (!isLeaf(curr))
            temp.push_back(curr->val);
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        res.push_back(temp[i]);
    }
}

// this will add the leafes in the binaryTree
void Leaves(TreeNode *root, vector<int> &res)
{
    if (isLeaf(root))
    {
        res.push_back(root->val);
        return;
    }
    if (root->left)
        Leaves(root->left, res);
    if (root->right)
        Leaves(root->right, res);
}

// this will check weather a given root is leaf or not
bool isLeaf(TreeNode *root)
{
    if (root->left == NULL and root->right == NULL)
        return true;
    return false;
}

// this is the main fucntion
vector<int> BoundaryTraversal(TreeNode *root)
{
    vector<int> res;
    if (root == NULL)
        return res;
    if (!isLeaf(root))
        res.push_back(root->val);
    leftBoundary(root, res);
    Leaves(root, res);
    rightBoundary(root, res);
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        TreeNode *root = TakeInputTree();
        vector<int> finalans = BoundaryTraversal(root);
        for (auto e : finalans)
            cout << e << " ";
    }
    return 0;
}