#include <stdio.h>

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int numbers[n];

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    printf("Minimum and maximum value sequences for each number:\n");

    for (int i = 0; i < n; i++) {
        int minSeq = numbers[i];
        int maxSeq = numbers[i];

        for (int j = i + 1; j < n; j++) {
            if (numbers[j] < minSeq) {
                minSeq = numbers[j];
            }

            if (numbers[j] > maxSeq) {
                maxSeq = numbers[j];
            }

            printf("For %d: Min: %d, Max: %d\n", numbers[i], minSeq, maxSeq);
        }
    }

    return 0;
}

