#include <iostream>
#include <vector>
#include "TakeInput.cpp"

using namespace std;

void rightSide(Node *root, vector<int> &res)
{
    Node *curr = root->right;
    while (curr)
    {
        res.push_back(curr->data);
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }
}

void leftSide(Node *root, vector<int> &res)
{
    vector<int> temp;
    Node *curr = root->left;
    while (curr)
    {
        temp.push_back(curr->data);
        if (curr->left)
            curr = curr->left;
        else
        {
            curr = curr->right;
        }
    }
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        res.push_back(temp[i]);
    }
}

vector<int> TopViewBinayTree(Node *root)
{
    vector<int> res;
    if (root == NULL)
        return res;
    leftSide(root, res);
    res.push_back(root->data);
    rightSide(root, res);
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *root = TakeInputTree();
        vector<int> ans = TopViewBinayTree(root);
        for (auto e : ans)
            cout << e << " ";
        cout << endl;
    }
    return 0;
}