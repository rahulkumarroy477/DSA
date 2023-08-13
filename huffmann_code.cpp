#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    pair<int, char> data;
    Node* left;
    Node* right;
    Node(int data, char c) {
        this->data.first = data;
        this->data.second = c;
        this->left = NULL;
        this->right = NULL;
    }
};

struct CompareNodes {
    bool operator()(const Node* a, const Node* b) const {
        return a->data > b->data;
    }
};

void inorder(Node* root, unordered_map<char,string> &ans, string &temp) {
    if (root->data.second != '*') {
        ans.insert({root->data.second,temp});
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        ans.insert({root->data.second,temp});
        return;
    }
    if (root->left) {
        temp.push_back('0');
        inorder(root->left, ans, temp);
        temp.pop_back();
    }
    if (root->right) {
        temp.push_back('1');
        inorder(root->right, ans, temp);
        temp.pop_back();
    }
}

int main() {
    priority_queue<Node*, vector<Node*>, CompareNodes> minHeap;
    // string str = "COMMITTEE";
    string str;
    cout<<"Enter message : ";
    cin>>str;
    int total_len = str.length();

    // calculate probability
    unordered_map<char, int> p;
    for (int i = 0; i < total_len; i++) {
        p[str[i]]++;
    }
    for (auto x : p) {
        minHeap.push(new Node(x.second, x.first));
    }

    // priority_queue<Node*, vector<Node*>, CompareNodes> minHeapCopy = minHeap;

    // cout << "\nElements of minHeap:\n";
    // while (!minHeapCopy.empty()) {
    //     cout << "Value: " << minHeapCopy.top()->data.first << ", Char: " << minHeapCopy.top()->data.second << "\n";
    //     minHeapCopy.pop();
    // }
    while (minHeap.size() != 1) {
        Node* first = minHeap.top();
        minHeap.pop();
        // cout<<first->data.first<<" "<<first->data.second<<endl;
        Node* second = minHeap.top();
        minHeap.pop();
        // cout<<second->data.first<<" "<<second->data.second<<endl;

        int val = first->data.first + second->data.first; 
        Node* root = new Node(val, '*');
        root->left = second;
        root->right = first;
        minHeap.push(root);
    }
    Node* root = minHeap.top();

    // levelOrderTraversal(root);
    // cout<<root->data.first<<" "<<root->data.second<<endl;
    unordered_map<char,string> ans;
    string temp;
    inorder(root,ans,temp);
    cout << "Huffman Codes:\n";
    for (const auto& code : ans) {
        cout << code.first <<"->"<<code.second<< "\n";
    }

    // coded message
    string newMsg;
    for(int i =0;i<total_len;i++)
    {
        newMsg += ans[str[i]];
    }
    cout<<str<<" -> "<<newMsg<<endl;
    return 0;
}
