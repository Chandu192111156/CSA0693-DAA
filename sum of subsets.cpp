#include <stdio.h>

#define MAX_SIZE 100

int set[MAX_SIZE];
int subset[MAX_SIZE];
int n;
int targetSum;
int found = 0;

void subsetSum(int index, int currentSum) {
    if (currentSum == targetSum) {
        found = 1;
        printf("Subset with sum %d found: {", targetSum);
        for (int i = 0; i < index; i++) {
            if (subset[i]) {
                printf(" %d", set[i]);
            }
        }
        printf(" }\n");
        return;
    }

    if (index == n || currentSum > targetSum || found) {
        return;
    }

    
    subset[index] = 1;
    subsetSum(index + 1, currentSum + set[index]);

    
    subset[index] = 0;
    subsetSum(index + 1, currentSum);
}

int main() {
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    subsetSum(0, 0);

    if (!found) {
        printf("No subset found with sum %d.\n", targetSum);
    }

    return 0;
}

