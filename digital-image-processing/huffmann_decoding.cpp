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

void traverse(int x,Node* root, string &temp,string &ans) {
    if(x==temp.length())    return;
    if (root->data.second != '*') {
        ans.push_back(root->data.second);
        return;
    }
    if(temp[x]=='0')    traverse(x+1,root->left,temp,ans);
    else if(temp[x]=='1')   traverse(x+1,root->right,temp,ans);
}
