#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<pair<char,char>,bool>>  edges;
    for(int i =0;i<m;i++)
    {
        int x,y;
        bool z;
        cin>>x>>y>>z;
        edges.push_back({{x,y},z});
    }
    
}