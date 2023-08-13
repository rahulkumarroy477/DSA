#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

bool isLeaf(Node *root)
{
    return root->left == NULL and root->right == NULL;
}
void printLeaf(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (isLeaf(root))
        ans.push_back(root->data);
    printLeaf(root->left, ans);
    printLeaf(root->right, ans);
}
void leftPart(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        if (isLeaf(st.top()))
            break;
        Node *node = st.top();
        st.pop();
        ans.push_back(node->data);
        if (node->right != NULL)
            st.push(node->right);
        if (node->left != NULL)
            st.push(node->left);
    }
}

int main()
{
    Node *root = NULL;
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    // vector<int> ans;
    // leftPart(root, ans);
    // for (auto x : ans)
    //     cout << x << " ";
    // cout << endl;
    // printLeaf(root, ans);
    // for (auto x : ans)
    //     cout << x << " ";
    // cout << endl;

    return 0;
}