#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    pair<int, char> data;
    Node* left;
    Node* mid;
    Node* right;
    Node(int data, char c) {
        this->data.first = data;
        this->data.second = c;
        this->left = NULL;
        this->mid = NULL;
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
    if (root == NULL) return;
    
    if (root->left) {
        temp.push_back('0');
        inorder(root->left, ans, temp);
        temp.pop_back();
    }
    if (root->mid) {
        temp.push_back('1');
        inorder(root->mid, ans, temp);
        temp.pop_back();
    }
    if (root->right) {
        temp.push_back('2');
        inorder(root->right, ans, temp);
        temp.pop_back();
    }
}

int main() {
    priority_queue<Node*, vector<Node*>, CompareNodes> minHeap;
    string str;
    cout << "Enter message: ";
    cin >> str;
    int total_len = str.length();

    // calculate probability
    unordered_map<char, int> p;
    for (int i = 0; i < total_len; i++) {
        p[str[i]]++;
    }
    for (auto x : p) {
        minHeap.push(new Node(x.second, x.first));
    }

    while (minHeap.size() > 2) {
        Node *first, *second, *third;
        first = second = third = NULL;
        first = minHeap.top();
        minHeap.pop();
        second = minHeap.top();
        minHeap.pop();

        int val = first->data.first + second->data.first;
        Node* root = new Node(val, '*');
        root->mid = second;
        root->left = third;
        root->right = first;
        minHeap.push(root);
    }

    Node* root = new Node(0, '*');
    root->left = minHeap.top();
    minHeap.pop();
    root->mid = minHeap.top();
    minHeap.pop();

    unordered_map<char,string> ans;
    string temp;
    inorder(root, ans, temp);

    cout << "Ternary Huffman Codes:\n";
    for (const auto& code : ans) {
        cout << code.first <<" -> "<<code.second<< "\n";
    }

    // Encode the message
    string newMsg;
    for (int i = 0; i < total_len; i++) {
        newMsg += ans[str[i]];
    }
    cout << "Encoded message: " << newMsg << endl;

    return 0;
}
