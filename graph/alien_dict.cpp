#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<string> input;
    int n;
    cin>>n;
    for(int i =0;i<n;i++)
    {
        string str;
        cin>>str;
        input.push_back(str);
    }
    vector<int> graph[26];
    for(int i =0;i<n-1;i++)
    {
        string str1 = input[i];
        string str2 = input[i+1];
        int size = max(str1.length(),str2.length());
        for(int i = 0;i<size;i++)
        {
            if(str1[i]!=str2[i])    graph[str1[i]].push_back(str2[i]);
        }
    }
}