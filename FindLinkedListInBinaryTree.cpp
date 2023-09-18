bool checkPath(ListNode *head, TreeNode *root)
{
    if (!head)
        return true;
    if (!root)
        return false;
    if (root->val == head->val)
    {
        return checkPath(head->next, root->right) || checkPath(head->next, root->left);
    }
    return false;
}
bool isSubPath(ListNode *head, TreeNode *root)
{
    if (root == NULL)
    {
        return false;
    }
    if (checkPath(head, root))
    {
        return true;
    }
    return isSubPath(head, root->right) || isSubPath(head, root->left);
}
