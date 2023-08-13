#include<iostream>
using namespace std;
int knap(int* wt, int* p,int n, int W)
{
    int k[n+1][W+1];
    for(int i =0;i<=n;i++)
    {
        for(int j = 0;j<=W;j++)
        {
            if(i==0||j==0)  k[i][j]=0;
            else if(wt[i]<=j)
            {
                k[i][j]= max(k[i-1][j],p[i]+k[i-1][j-wt[i]]);
            }
            else k[i][j]=k[i-1][j];
        }
    }

    // given dp table
    cout<<"Required dp table will be : \n";
    for(int i =0;i<=n;i++)
    {
        for(int j =0;j<=W;j++)
            cout<<k[i][j]<<"  ";
        cout<<endl;
    }
    return k[n][W];
}
int main()
{
    int n,W;
    printf("Enter no. of items: ");
    cin>>n;
    printf("Enter the size of Knapsack: ");
    cin>>W;
    int wt[n+1],profit[n+1];
    printf("Enter profit of items: ");
    for(int i =0;i<=n;i++)  cin>>profit[i];
    printf("Enter weight of items: ");
    for(int i =0;i<=n;i++)  cin>>wt[i];
    // max profit will be
    cout<<"Max profit is "<<knap(wt,profit,n,W);
}
/*
input
4 8
0 1 2 5 6
0 2 3 4 5
*/