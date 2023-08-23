#include <stdio.h>

#define MAX_CONTAINERS 100

void containerLoading(int items[], int numItems, int containerCapacity) {
    int containers[MAX_CONTAINERS] = {0};
    int numContainers = 0;

    for (int i = 0; i < numItems; i++) {
        int placed = 0;

        for (int j = 0; j < numContainers; j++) {
            if (containers[j] + items[i] <= containerCapacity) {
                containers[j] += items[i];
                placed = 1;
                break;
            }
        }

        if (!placed) {
            containers[numContainers++] = items[i];
        }
    }

    printf("Container loading result:\n");
    for (int i = 0; i < numContainers; i++) {
        printf("Container %d: %d\n", i + 1, containers[i]);
    }
}

int main() {
    int numItems, containerCapacity;

    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    int items[numItems];
    printf("Enter the weights of items:\n");
    for (int i = 0; i < numItems; i++) {
        scanf("%d", &items[i]);
    }

    printf("Enter the container capacity: ");
    scanf("%d", &containerCapacity);

    containerLoading(items, numItems, containerCapacity);

    return 0;
}

