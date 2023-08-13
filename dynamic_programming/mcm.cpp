#include <bits/stdc++.h>
using namespace std;

// recursion

// int mcm(vector<int> arr, int i, int j)
// {
//     if (i == j)
//         return 0;
//     int mini = INT_MAX;
//     for (int k = i; k < j; k++)
//     {
//         int solve = arr[i - 1] * arr[k] * arr[j] + mcm(arr, i, k) + mcm(arr, k + 1, j);
//         mini = min(mini, solve);
//     }
//     return mini;
// }

// memoization

int mcm(int i,int j,vector<int> arr,vector<vector<int>> &dp)
{
    if (i == j)
        return dp[i][j]= 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int mini = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int solve = arr[i - 1] * arr[k] * arr[j] + mcm(i, k,arr,dp) + mcm(k + 1, j,arr,dp);
        mini = min(mini, solve);
    }
    return dp[i][j]= mini;
}

int main()
{
    vector<int> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    vector<vector<int>> dp(n,vector<int>(n,-1));
    // recursion
    // cout << mcm(arr, 1, n - 1) << endl;

    // memoization
    cout<<mcm(1,n-1,arr,dp);
}


