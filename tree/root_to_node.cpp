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
bool rootToNode(Node *root, int target, vector<int> &vec)
{
    if (root == NULL)
        return false;
    vec.push_back(root->data);
    // for (auto x : vec)
    //     cout << x << " ";
    // cout << endl;
    if (root->data == target)
        return true;
    if (rootToNode(root->left, target, vec) or rootToNode(root->right, target, vec))
        return true;
    vec.pop_back();
    return false;
}
int lowestCommonAncestor(Node* root,int a,int b)
{
    vector<int> path1,path2;
    if(a==b)    return a;
    rootToNode(root,a,path1);
    rootToNode(root,b,path2);
    int i =0;
    int ans;
    while(true)
    {
        if(path1[i]==path2[i])  ans= path1[i++];
        else return ans;
    }
    return ans;
}

// optimized

int lca(Node* root,int a,int b)
{
    if(root==NULL)  return 0;
    if(root->data==a or root->data==b)  return root->data;
    int left = lca(root->left,a,b);
    int right = lca(root->right,a,b);
    if(left ==0 and right==0)   return 0;
    else if(left ==0 and right!=0)  return right;
    else if(left!=0 and right==0)  return left;
    else return root->data;
    
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
    // int target;
    // cin >> target;
    // vector<int> vec;
    // rootToNode(root, target, vec);

    
    int a,b;
    cin>>a>>b;
    cout<<lowestCommonAncestor(root,a,b)<<endl;
    cout<<lca(root,a,b)<<endl;
    return 0;
}
//      The given tree : - 
// 
//                          1
//                         / \
//                        2   3 
//                       / \   
//                      4   5
//                         / \
//                        6   7 

