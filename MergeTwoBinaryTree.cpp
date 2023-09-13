#include <iostream>
#include <vector>
#include "TakeInput.cpp"

using namespace std;

TreeNode *MergedTree(TreeNode *root1, TreeNode *root2)
{
    if (root1 != NULL and root2 == NULL)
    {
        return root1;
    }
    if (root1 == NULL and root2 != NULL)
    {
        return root2;
    }
    TreeNode *root = new TreeNode(root1->val + root2->val);
    root->left = MergedTree(root1->left, root2->left);
    root->right = MergedTree(root1->right, root1->right);
    return root;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        TreeNode *root1 = TakeInputTree();
        TreeNode *root2 = TakeInputTree();
        TreeNode *finalTree = MergedTree(root1, root2);
        printTree(finalTree);
    }
    return 0;
}