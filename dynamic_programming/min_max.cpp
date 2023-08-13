#include<iostream>
using namespace std;

pair<int,int> min_max(int s,int l,int arr[])
{
    if(s==l) return {arr[s],arr[l]};
    if(l-s==1)  return {min(arr[s],arr[l]),max(arr[s],arr[l])};
    else 
    {
        int mid = (s+l)/2;
        auto p = min_max(s,mid,arr);
        auto q = min_max(mid+1,l,arr);
        return {min(p.first,q.first),max(p.second,q.second)};
    }
}
int main()
{
    int arr[]={12,3,4,5,6,8,10,-1};
    auto ans = min_max(0,7,arr);
    cout<<"MIN: "<<ans.first<<"\nMax: "<<ans.second<<endl;
}