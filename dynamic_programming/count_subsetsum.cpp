#include<bits/stdc++.h>
using namespace std;

int countSubsetSum(int arr[],int n,int sum)
{
    int dp[n+1][sum+1];
    for(int j=0;j<n+1;j++)
        dp[j][0] = 1;
    for(int i = 1;i<sum+1;i++)
        dp[0][i] = 0;
    for(int i = 1;i<n+1;i++)
    {
        for(int j = 1;j<sum+1;j++)
        {
            if(j<arr[i-1])  dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i-1][j]+dp[i-1
            ][j-arr[i-1]];
        }
    }
    for(int i = 0;i<n+1;i++)
    {
        for(int j = 0;j<sum+1;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][sum];
}

bool equalSumPartition(int arr[], int sum) {
    if(sum%2!=0) return false;
    return equalSumPartition(arr, sum/2);
}
int main()
{
    int n = 4;
    int arr[4] ={1,2,2,3};
    cout<<countSubsetSum(arr,4,4)<<endl;

    // equal sum partition function
    int sum =0;
    for(int i=0;i<n;i++)   sum += arr[i];
    cout<<equalSumPartition(arr,sum)<<endl;
    return 0;
}