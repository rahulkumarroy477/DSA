#include <bits/stdc++.h>
using namespace std;

// A tree node
// struct Node
// {
//     int data;
//     struct Node *left, *right;
// };

// // A utility function to create a new tree node
// struct Node *newNode(int data)
// {
//     struct Node *node = new Node;
//     node->data = data;
//     node->left = node->right = NULL;
//     return node;
// }

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

vector<int> preorder(Node *root)
{
    vector<int> preorder;
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        auto node = st.top();
        st.pop();
        preorder.push_back(node->data);
        if (node->right != NULL)
            st.push(node->right);
        if (node->left != NULL)
            st.push(node->left);
    }
    return preorder;
}

vector<int> postorder(Node *root)
{
    vector<int> postorder;
    stack<Node *> st1, st2;
    st1.push(root);
    while (!st1.empty())
    {
        auto node = st1.top();
        st1.pop();
        st2.push(node);
        if (node->left != NULL)
            st1.push(node->left);
        if (node->right != NULL)
            st1.push(node->right);
    }
    while (!st2.empty())
    {
        postorder.push_back(st2.top()->data);
        st2.pop();
    }
    return postorder;
}

vector<int> inorder(struct Node *root)
{
    vector<int> inorder;
    struct Node *node = root;

    stack<struct Node *> st;
    while (true)
    {
        if (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty())
                break;
            inorder.push_back(st.top()->data);
            node = st.top()->right;
            st.pop();
        }
    }
    return inorder;
}

// function to build tree

Node *buildTree(Node *root)
{
    int data;
    cout << "Enter data : " << endl;
    cin >> data;
    root = new Node(data);
    if (data == -1)
        return NULL;

    cout << "Left child of " << data << endl;
    root->left = buildTree(root->left);
    cout << endl;
    cout << "Right child of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

vector<int> levelorder(Node *root)
{
    Node *node = root;
    vector<int> levelorder;
    queue<Node *> q;
    q.push(node);
    while (!q.empty())
    {
        node = q.front();
        q.pop();
        levelorder.push_back(node->data);
        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
    }
    return levelorder;
}

//  height of a tree

int height(Node *root)
{
    if (root == NULL)
        return 0;
    int left = height(root->left);
    int right = height(root->right);
    return 1 + max(left, right);
}

// diameter of a tree

int diameter(Node *root, int &maxi)
{
    if (root == NULL)
        return 0;
    int lh = diameter(root->left, maxi);
    int rh = diameter(root->right, maxi);
    maxi = max(maxi, lh + rh);
    cout << maxi << endl;
    return 1 + max(lh, rh);
}

vector<int> top_view(Node *root)
{
    vector<int> ans;
    Node *node = root;

    // left view

    while (node != NULL)
    {
        ans.push_back(node->data);
        node = node->left;
    }
    reverse(ans.begin(), ans.end());
    node = root->right;

    // right view

    while (node != NULL)
    {
        ans.push_back(node->data);
        node = node->right;
    }
    return ans;
}

void reverseLevelOrder(Node *root)
{
    stack<Node *> st;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        if (temp->right)
            q.push(temp->right);
        if (temp->left)
            q.push(temp->left);
        st.push(temp);
    }
    while (!st.empty())
    {
        cout << st.top()->data << " ";
        st.pop();
    }
}
Node *makeMirror(Node *root)
{
    if (root)
    {
        makeMirror(root->left);
        makeMirror(root->right);
        // swap the pointers

        Node *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    return root;
}

void verticalOrderTraversal(Node *root)
{
    map<int, map<int, multiset<int>>> mp;
    queue<pair<pair<int, int>, Node *>> q;
    q.push({{0, 0}, 0});
    while (!q.empty())
    {
        auto itr = q.front();
        q.pop();
        int x = itr.first.first;  // vertical
        int y = itr.first.second; // level
        Node *node = itr.second;

        if (node->left)
        {
            q.push({{x - 1, y + 1}, node->left});
            mp[x - 1][y + 1].insert(node->left->data);
        }
        if (node->right)
        {
            q.push({{x + 1, y + 1}, itr.second->right});
            mp[x + 1][y + 1].insert(node->right->data);
        }
    }
    for (const auto &entry : mp)
    {
        int outerKey = entry.first;
        const auto &innerMap = entry.second;

        std::cout << "Outer Key: " << outerKey << std::endl;

        for (const auto &innerEntry : innerMap)
        {
            int innerKey = innerEntry.first;
            const auto &innerSet = innerEntry.second;

            std::cout << "  Inner Key: " << innerKey << std::endl;

            for (int value : innerSet)
            {
                std::cout << "    Value: " << value << std::endl;
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
    // root= buildTree(root);

    // preorder
    // vector<int> pre = preorder(root);
    // for(auto x:pre) cout<<x<<" ";           // 1 2 4 5 3 6 7
    // cout<<endl;

    // // postorder
    // vector<int> post = postorder(root);
    // for(auto x:post) cout<<x<<" ";          // 4 5 2 6 7 3 1
    // cout<<endl;

    // // inorder
    // vector<int> inor = inorder(root);
    // for(auto x:inor) cout<<x<<" ";          // 4 2 5 1 6 3 7
    // cout<<endl;

    // // levelorder travesal
    // vector<int> lot = levelorder(root);     // 1 2 3 4 5 6 7
    // for(auto x:lot) cout<<x<<" ";
    // cout<<endl;

    // // Height
    // cout<<"Height : "<<height(root)<<endl;

    // // diameter and height
    // // int maxi = 0;
    // // cout<<"Diameter : "<<diameter(root,maxi)<<" "<<maxi<<endl;
    // cout<<"Top view : "<<endl;
    // vector<int> topView = top_view(root);
    // for(auto x:topView) cout<<x<<" ";cout<<endl;

    // reverseLevelOrder(root);
    verticalOrderTraversal(root);
}