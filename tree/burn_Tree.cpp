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

vector<vector<int>> levelOrderTraversal(Node *root)
{
    vector<vector<int>> ans;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        vector<int> temp;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();
            temp.push_back(node->data);
            if (node->left)
            {
                q.push(node->left);
                // temp.push_back(node->data);
            }
            if (node->right)
            {
                q.push(node->right);
                // temp.push_back(node->data);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}
Node *mapNodeToParent(Node *root, map<Node *, Node *> &mp, int target)
{
    stack<Node *> s;
    s.push(root);
    Node *ans = NULL;
    while (!s.empty())
    {
        auto node = s.top();
        s.pop();
        if (node->data == target)
            ans = node;
        if (node->right)
        {
            s.push(node->right);
            mp[node->right] = node;
        }
        if (node->left)
        {
            s.push(node->left);
            mp[node->left] = node;
        }
    }
    return ans;
}

void traversalFromTarget(Node *root, int val)
{
    map<Node *, Node *> mp;
    Node *target = mapNodeToParent(root, mp, val);
    cout << target->data << endl;
    cout << "Node to parent\n";
    for (auto x : mp)
    {
        cout << x.first->data << " " << x.second->data << endl;
    }

    map<Node *, bool> vis;
    queue<Node *> q;
    q.push(target);
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        cout << node->data << endl;
        // check parent
        if (node != root)
        {
            if (!vis[mp[node]])
            {
                vis[mp[node]] = true;
                q.push(mp[node]);
            }
        }
        // check left
        if (!vis[mp[node->left]] and node->left)
        {
            vis[mp[node->left]] = true;
            q.push(mp[node->left]);
        }
        if (!vis[mp[node->right]] and node->left)
        {
            vis[mp[node->left]] = true;
            q.push(mp[node->left]);
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
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    // vector<vector<int>> lot = levelOrderTraversal(root);
    // for(auto x:lot)
    // {
    //     for(auto y: x)  cout<<y<<" ";
    //     cout<<endl;
    // }
    traversalFromTarget(root, 4);
    return 0;
}

/*     The given tree : -
//
//                          1
/*                         / \      */
//                        2   3
//                       / \        */
//                      4   5
//                         / \      */
//                        6   7