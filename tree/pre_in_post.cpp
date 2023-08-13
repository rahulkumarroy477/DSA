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
void pre_ino_post(Node *root, vector<int> &preorder, vector<int> &inorder, vector<int> &postorder)
{
    stack<pair<Node *, int>> st;
    st.push({root, 1});
    while (!st.empty())
    {
        auto node = st.top();
        st.pop();
        if (node.second == 1)
        {
            preorder.push_back(node.first->data);
            node.second++;
            st.push(node);
            if (node.first->left != NULL)
                st.push({node.first->left, 1});
        }
        else if (node.second == 2)
        {
            inorder.push_back(node.first->data);
            node.second++;
            st.push(node);
            if (node.first->right != NULL)
                st.push({node.first->right, 1});
        }
        else
        {
            postorder.push_back(node.first->data);
        }
    }
}
int height(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}
int diameter(Node *root, int &maxi)
{
    if (root == NULL)
        return 0;
    return maxi = max(height(root->left) + height(root->right), maxi);
}
int main()
{
    Node *root = NULL;
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // vector<int> postorder, inorder, preorder;
    // pre_ino_post(root,preorder,inorder,postorder);
    // for(auto x:preorder)    cout<<x<<" ";
    // cout<<endl;
    // for(auto x:inorder)    cout<<x<<" ";
    // cout<<endl;
    // for(auto x:postorder)    cout<<x<<" ";
    // cout<<endl;
    int maxi = 0;
    cout << height(root) << endl;
    cout << diameter(root, maxi) << endl;
    return 0;
}

// output
// 1 2 4 5 3 6 7
// 4 2 5 1 6 3 7
// 4 5 2 6 7 3 1