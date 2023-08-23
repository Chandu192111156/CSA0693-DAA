#include <stdio.h>
int findLargestElement(int arr[], int size) {
    int largest = arr[0]; 

    for (int i = 1; i < size; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    return largest;
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int array[size];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    int largest = findLargestElement(array, size);
    printf("The largest element in the array is: %d\n", largest);

    return 0;
}


