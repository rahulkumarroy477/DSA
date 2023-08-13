// find the sum of all nodes whose grandparent data is even

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

int sumOfGp(Node *root)
{
    int sum = 0;
    if (root == NULL)
        return 0;

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        bool even = (node->data) % 2 == 0;
        if (node->left!=NULL)
        {
            q.push(node->left);
            if (even)
            {

                if (node->left->left!=NULL)
                    sum += node->left->left->data;
                if (node->left->right!=NULL)
                    sum += node->left->right->data;
            }

        }
        if(node->right!=NULL)
        {
            q.push(node->right);
            if (even)
            {

                if (node->right->left!=NULL)
                    sum += node->right->left->data;
                if (node->right->right!=NULL)
                    sum += node->right->right->data;
            }
        }
    }
    return sum;
}
int main()
{
    Node *root = NULL;
    root = new Node(22);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(4);
    root->left->right = new Node(8);
    root->right->left = new Node(1);
    root->right->right = new Node(9);
    root->right->right->right = new Node(2);
    cout<<sumOfGp(root)<<endl;
}