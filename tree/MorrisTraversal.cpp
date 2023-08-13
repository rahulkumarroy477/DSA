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
void morris(Node *root)
{
    Node* curr = root;
    while (curr!=NULL)
    {
        if (curr->left == NULL)
        {
            cout<<curr->data<<endl;
            curr = curr->right;
        }
        else
        {
            Node* prev = curr->left;
            while(prev->right and prev->right!=curr)
            {
                prev = prev->right;
            }
            if(prev->right==NULL)  
            {
                prev->right = curr;
                curr=curr->left;
            }
            else
            {
                prev->right=NULL;
                cout<<curr->data<<endl;
                curr=curr->right;
            }
        }
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
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    morris(root);
}