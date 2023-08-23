#include <stdio.h>
#include <limits.h>

#define MAX_CITIES 10

int numCities;
int distances[MAX_CITIES][MAX_CITIES];
int dp[MAX_CITIES][1 << MAX_CITIES];

int min(int a, int b) {
    return (a < b) ? a : b;
}

int tsp(int current, int mask) {
    if (mask == (1 << numCities) - 1) {
        return distances[current][0];
    }

    if (dp[current][mask] != -1) {
        return dp[current][mask];
    }

    int minDistance = INT_MAX;
    for (int i = 0; i < numCities; i++) {
        if ((mask & (1 << i)) == 0) {
            minDistance = min(minDistance, distances[current][i] + tsp(i, mask | (1 << i)));
        }
    }

    return dp[current][mask] = minDistance;
}

int main() {
    printf("Enter the number of cities: ");
    scanf("%d", &numCities);

    printf("Enter the distance matrix:\n");
    for (int i = 0; i < numCities; i++) {
        for (int j = 0; j < numCities; j++) {
            scanf("%d", &distances[i][j]);
        }
    }

    for (int i = 0; i < numCities; i++) {
        for (int j = 0; j < (1 << numCities); j++) {
            dp[i][j] = -1;
        }
    }

    int minTourDistance = tsp(0, 1);
    printf("Minimum tour distance: %d\n", minTourDistance);

    return 0;
}

