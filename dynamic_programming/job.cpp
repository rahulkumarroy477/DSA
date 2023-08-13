#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline, profit;
};

bool cmp(Job a, Job b) {
    return (a.profit > b.profit);
}

void jobScheduling(Job arr[], int n) {
    sort(arr, arr + n, cmp);
    int result[n];
    bool slot[n];
    for(int i = 0; i < n; i++) {
        slot[i] = false;
    }
    for(int i = 0; i < n; i++) {
        for(int j = min(n, arr[i].deadline) - 1; j >= 0; j--) {
            if(slot[j] == false) {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }
    int totalProfit = 0;
    for(int i = 0; i < n; i++) {
        if(slot[i]) {
            totalProfit += arr[result[i]].profit;
            cout << arr[result[i]].id << " ";
        }
    }
    cout << endl << "Total Profit: " << totalProfit << endl;
}

int main() {
    Job arr[] = {{'1', 2, 20}, {'2', 2, 15}, {'3',1, 10},
                  {'4', 3, 5}, {'5', 3, 1}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Job sequence is: ";
    jobScheduling(arr, n);
    return 0;
}