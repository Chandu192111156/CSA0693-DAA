#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int list[MAX_SIZE];
    int size, num, position;

    printf("Enter the size of the list (up to %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid size.\n");
        return 1; 
    }

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &list[i]);
    }

    printf("Enter the number to insert: ");
    scanf("%d", &num);

    printf("Enter the position to insert (1 to %d): ", size + 1);
    scanf("%d", &position);

    if (position < 1 || position > size + 1) {
        printf("Invalid position.\n");
        return 1; 
    }

    
    for (int i = size; i >= position; i--) {
        list[i] = list[i - 1];
    }

   
    list[position - 1] = num;
    size++;

    printf("List after insertion:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    return 0;
}

