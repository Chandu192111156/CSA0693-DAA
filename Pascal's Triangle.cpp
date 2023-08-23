#include <stdio.h>


int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    int numRows;

    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &numRows);

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j <= numRows - i; j++)
            printf(" "); 

        for (int j = 0; j <= i; j++)
            printf("%d ", factorial(i) / (factorial(j) * factorial(i - j)));

        printf("\n");
    }

    return 0;
}

