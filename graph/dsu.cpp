#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
int parent[N];
void make(int v)
{
    parent[v]=v;
}
int find(int v)
{
    if(v==parent[v])    return v;
    return find(parent[v]);
}
void Union(int a,int b)
{

}
int main()
{

}