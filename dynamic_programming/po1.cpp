#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    string a,b;
	    cin>>a>>b;
	    int n;
	    cin>>n;
	    a= a+b;
	    unordered_map<char,int> p,q;
	    for(int i =0;i<a.length();i++)
	        p[a[i]]++;
	        
	    for(int i = 0;i<n;i++)
	    {
	        string temp;
	        cin>>temp;
	        for(int j=0;j<temp.length();j++)
	            q[temp[j]]++;
	    }
	    bool ans = true;
	    for(auto x:q)
	    {
	        auto it = p.find(x.first);
	        if(it == p.end())   ans = false;
	        else
	        {
	            if(x.second<=it->second)	continue;
				else ans = false;
	        }
	        
	    }
	    if(ans) cout<<"YES\n";
	    else cout<<"NO\n";
	}
	return 0;
}
