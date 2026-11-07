# Lab 11 — Matrix Chain Multiplication using Dynamic Programming

**Course:** CSE-204 — Design and Analysis of Algorithms  
**Method:** Dynamic Programming

## Problem
Implement Matrix Chain Multiplication using Dynamic Programming to find the minimum number of scalar multiplications required to multiply a sequence of matrices.

## Method
Let `dp[i][j]` be the minimum multiplication cost for matrices `Ai` through `Aj`.

`dp[i][j] = min(dp[i][k] + dp[k+1][j] + p[i-1] × p[k] × p[j])`, for `i ≤ k < j`.

Base case: `dp[i][i] = 0`. A split table records the optimal split to reconstruct the parenthesization.

## Sample Input
```text
4
10 30 5 60 2
```

The first number is the matrix count, followed by `n + 1` dimensions.

## Sample Output
```text
Enter Number of Matrices: Enter 5 dimensions: Minimum Number of Scalar Multiplications: 1500
Optimal Parenthesization: ((A1(A2A3))A4)
```

## Complexity
- **Time:** `O(n^3)`
- **Space:** `O(n^2)`

## Files
- `Source_Code/1_Matrix_Chain_Multiplication.cpp`
- `Output/Program_Output.txt`
- `Docs/` — lab record PDF destination
