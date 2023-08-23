#include <stdio.h>


int binomialCoefficient(int n, int k) {
    int dp[n + 1][k + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k && j <= i; j++) {
            if (j == 0 || j == i) {
                dp[i][j] = 1; 
            } else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }

    return dp[n][k];
}

int main() {
    int n = 5, k = 2; 
    printf("C(%d, %d) = %d\n", n, k, binomialCoefficient(n, k));
    return 0;
}

