#include<bits/stdc++.h>
using namespace std;
void dfs(int i, int j, vector<vector<int>> &matrix, int color, int initcolor) {
    int n = matrix.size();
    int m = matrix[0].size();
    if (i < 0 || i >= n || j < 0 || j >= m || matrix[i][j]!=initcolor) return;

    matrix[i][j] = color;
    // Check if i and j are within bounds

    // Check if the cell has the initial color
    
        dfs(i - 1, j, matrix, color, initcolor);
        dfs(i + 1, j, matrix, color, initcolor);
        dfs(i, j - 1, matrix, color, initcolor);
        dfs(i, j + 1, matrix, color, initcolor);
}
void floodfill(vector<vector<int>> &matrix,int sx, int sy, int color)
{
    int initcolor = matrix[sx][sy];
    dfs(sx,sy,matrix,color,initcolor);
}
int main()
{
    vector<vector<int>> matrix = {
        {1,1,1},
        {1,2,0},
        {1,0,1}
    };
    floodfill(matrix,1,1,2);
    for(auto x:matrix)
    {
        for(auto y :x)
        {
            cout<<y<<" ";
        }cout<<endl;
    }
}