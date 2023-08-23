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

bool comp(pair<char,int> a,pair<char,int> b)
{
    return a.second>b.second;
}
int main()
{
    unordered_map<char,int> mp;
    string str = "COMMITTEE";
    int str_len = str.length();
    for(int i =0;i<str_len;i++)
    {
        mp[str[i]]++;
    }
    cout<<"Entropy : "<<endl;
    double entropy = 0;
    for(auto x:mp)
    {
        double pk = (double)x.second/str_len;
        pk*=log2(pk);
        entropy-=pk;
    }
    cout<<entropy<<endl;
}