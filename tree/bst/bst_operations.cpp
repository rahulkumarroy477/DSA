#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;
        Node(int data)
        {
            this->data=data;
            this->left = this->right=NULL;
        }

};
Node* insert(Node* root,int data)
{
    if(root==NULL)  return new Node(data);
    if(root->data>data) root->left = insert(root->left,data);
    if(root->data<data) root->right = insert(root->right,data);
    return root;
}
void inorder(Node* root)
{
    if(root==NULL)  return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
bool search(Node* root,int data)
{
    if(root==NULL)  return false;
    if(root->data==data) return true;
    else if(root->data>data)    return search(root->left,data);
    else return search(root->right,data);
    return false;
}
Node* find(Node* root,int data)
{
    if(root==NULL or root->data==data)  return root;
    if(root->data>data) return find(root->left,data);
    else return find(root->right,data);
}
bool validateBST(Node* root,int a,int b)
{
    if(root==NULL)  return true;
    if(a<root->data and root->data<b)
    {
        return validateBST(root->left,a,root->data) and validateBST(root->right,root->data,b);
    }
    return false;
    // if(root==NULL)    return true;
    // if(root->data>=b or root->data<=a)    return false;
    // return validateBST(root->left,a,root->data) and validateBST(root->right,root->data,b);
}
int main()
{
    Node* root = NULL;

    root = new Node(5);
    root->left = new Node(1);
    root->right = new Node(7);
    root->right->left = new Node(6);
    root->right->right = new Node(8);
    inorder(root);
    cout<<endl;
    cout<<search(root,8)<<endl;
    Node* sRoot = find(root,8);
    cout<<sRoot->data<<endl;

    cout<<validateBST(root,INT_MIN,INT_MAX)<<endl;
}