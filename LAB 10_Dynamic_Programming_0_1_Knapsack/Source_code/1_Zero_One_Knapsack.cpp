/*
Program Name: 0/1 Knapsack Using Dynamic Programming
Program Description: Finds the maximum value that fits within a knapsack capacity.
Program Creation Time: Oct 30th, 2026
Program Creator: Ashwath Raj | AP25110010712
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n, capacity;
    cout << "Enter Number of Items and Knapsack Capacity: ";
    cin >> n >> capacity;

    vector<int> weight(n), value(n);
    cout << "Enter Weights of Items:" << endl;
    for (int i = 0; i < n; i++) cin >> weight[i];

    cout << "Enter Values of Items:" << endl;
    for (int i = 0; i < n; i++) cin >> value[i];

    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            dp[i][w] = dp[i - 1][w];
            if (weight[i - 1] <= w) {
                dp[i][w] = max(dp[i][w],
                               value[i - 1] + dp[i - 1][w - weight[i - 1]]);
            }
        }
    }

    cout << "Maximum Value: " << dp[n][capacity] << endl;
    cout << "Selected Items (1-based):";
    int w = capacity;
    vector<int> selected;
    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            selected.push_back(i);
            w -= weight[i - 1];
        }
    }
    reverse(selected.begin(), selected.end());
    if (selected.empty()) cout << " None";
    else for (int item : selected) cout << " " << item;
    cout << endl;
    return 0;
}
