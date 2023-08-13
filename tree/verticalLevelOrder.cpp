#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data= data;
            this->left = NULL;
            this->right = NULL;
        }
};

void verticalOrderTraversal(Node *root)
{
    map<int, map<int, multiset<int>>> mp;
    queue<pair<pair<int, int>, Node *>> q;
    q.push({{0, 0}, root});
    while (!q.empty())
    {
        auto itr = q.front();
        q.pop();
        int x = itr.first.first;  // vertical
        int y = itr.first.second; // level
        Node *node = itr.second;
        mp[x][y].insert(node->data);
        if (node->left)
        {
            q.push({{x - 1, y + 1}, node->left});
        }
        if (node->right)
        {
            q.push({{x + 1, y + 1}, itr.second->right});
        }
    }
    for(const auto it:mp)
    {
        for(const auto x:it.second)
        {
            for(const auto y:x.second)  cout<<y<<" ";
        }
        cout<<endl;
    }
}
int main()
{


     Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);
    // root= buildTree(root);


    verticalOrderTraversal(root);
    return 0;
}



