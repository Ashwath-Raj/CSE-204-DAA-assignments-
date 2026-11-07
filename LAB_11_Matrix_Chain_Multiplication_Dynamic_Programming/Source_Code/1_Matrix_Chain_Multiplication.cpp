/*
Program Name: Matrix Chain Multiplication using Dynamic Programming
Program Description: Finds the minimum scalar multiplication cost and
                      optimal parenthesization of a matrix chain.
Program Creation Time: Oct 31, 2026
Program Creator: Ashwath Raj | AP25110010712
*/

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

void printParenthesization(const vector<vector<int>>& split, int i, int j) {
    if (i == j) {
        cout << "A" << i;
        return;
    }
    cout << "(";
    printParenthesization(split, i, split[i][j]);
    printParenthesization(split, split[i][j] + 1, j);
    cout << ")";
}

int main() {
    int n;
    cout << "Enter Number of Matrices: ";
    cin >> n;

    if (!cin || n <= 0) {
        cerr << "Invalid number of matrices.\n";
        return 1;
    }

    vector<long long> p(n + 1);
    cout << "Enter " << n + 1 << " dimensions: ";
    for (long long& x : p) {
        cin >> x;
        if (!cin || x <= 0) {
            cerr << "Invalid dimensions. All dimensions must be positive.\n";
            return 1;
        }
    }

    const long long INF = numeric_limits<long long>::max();
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
    vector<vector<int>> split(n + 1, vector<int>(n + 1, 0));

    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i <= n - len + 1; ++i) {
            int j = i + len - 1;
            dp[i][j] = INF;

            for (int k = i; k < j; ++k) {
                __int128 cost = static_cast<__int128>(dp[i][k]) +
                    dp[k + 1][j] +
                    static_cast<__int128>(p[i - 1]) * p[k] * p[j];

                if (cost < dp[i][j] && cost <= INF) {
                    dp[i][j] = static_cast<long long>(cost);
                    split[i][j] = k;
                }
            }

            if (dp[i][j] == INF) {
                cerr << "Multiplication cost exceeds the supported range.\n";
                return 1;
            }
        }
    }

    cout << "Minimum Number of Scalar Multiplications: " << dp[1][n] << "\n";
    cout << "Optimal Parenthesization: ";
    printParenthesization(split, 1, n);
    cout << "\n";
    return 0;
}
