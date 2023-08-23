#include <stdio.h>
#include <stdbool.h>

#define N 4 

int cost[N][N] = {
    {9, 2, 7, 8},
    {6, 4, 3, 7},
    {5, 8, 1, 8},
    {7, 6, 9, 4}
};

bool assigned[N];
int assignment[N];

int minCost = 1e9; 
void solveAssignment(int worker, int currentCost) {
    if (worker == N) {
        if (currentCost < minCost) {
            minCost = currentCost;
            for (int i = 0; i < N; i++) {
                assignment[i] = assigned[i];
            }
        }
        return;
    }

    for (int task = 0; task < N; task++) {
        if (!assigned[task]) {
            assigned[task] = true;
            solveAssignment(worker + 1, currentCost + cost[worker][task]);
            assigned[task] = false;
        }
    }
}

int main() {
    for (int i = 0; i < N; i++) {
        assigned[i] = false;
        assignment[i] = -1;
    }

    solveAssignment(0, 0);

    printf("Minimum cost: %d\n", minCost);
    printf("Assignments:\n");
    for (int i = 0; i < N; i++) {
        printf("Worker %d -> Task %d\n", i + 1, assignment[i] + 1);
    }

    return 0;
}

