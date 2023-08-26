#include <bits/stdc++.h>
using namespace std;

void firstSecMin(int arr[], int n)
{
    int first = INT_MAX;
    int second = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < first)
        {
            first = arr[i];
        }
        if (arr[i] > first and second > arr[i])
            second = arr[i];
    }

    cout << first << " " << second << endl;
}
int main()
{
    int n = 9;
    int arr[n] = {1, 5, 8, 4, 7, 6, 5, 3, 1};

    firstSecMin(arr, n);
    // find from last where arr[i]>arr[i-1];
    int idx = 0;
    for (int i = n - 1; i > 0; i--)
    {
        if (arr[i] > arr[i - 1])
        {
            idx = i;
            break;
        }
    }

    // find first element greater than idx-1
    int temp = arr[idx - 1];
    // cout<<temp<<endl;
    int sMaxIndex = idx;
    int secondMax = INT_MAX;
    for (int i = idx; i < n; i++)
    {
        if (arr[i] > temp and arr[i] < secondMax)
        {
            secondMax = arr[i];
            sMaxIndex = i;
        }
    }
    cout << idx << " " << sMaxIndex << endl;
    swap(arr[idx-1],arr[sMaxIndex]);
    for(int i =0;i<n;i++)   cout<<arr[i]<<" ";
    cout<<endl;
    reverse(arr+idx,arr+n);
    for(int i =0;i<n;i++)   cout<<arr[i]<<" ";
}