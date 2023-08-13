#include<bits/stdc++.h>
using namespace std;
void shortest_distance(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for(int i =0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(matrix[i][j]==-1)    matrix[i][j]=1e9;
            if(i == j)  matrix[i][j]=0;
        }
    }

    for(int k = 0;k<n;k++)
    {
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<n;j++)
            {
                matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
            }
        }
    }

    for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++){
            if(matrix[i][j]==1e9)   matrix[i][j]=-1;
        }
    }
}
int main()
{
    int n;
    printf("Enter no. of vertices : ");
    cin>>n;
    vector<vector<int>> matrix;
    for(int i =0;i<n;i++)
    {
        vector<int> temp;
        for(int j = 0;j<n;j++)
        {
            int x;
            cin>>x;
            temp.push_back(x);
        }
        matrix.push_back(temp);
    }
    shortest_distance(matrix);
    printf("Shortest lab between every pair are : \n");
    for(int i =0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
        
    }


}

