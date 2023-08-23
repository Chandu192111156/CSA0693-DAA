#include <stdio.h>

int main() {
    int n;

    printf("Enter an integer: ");
    scanf("%d", &n);

    printf("Factors of %d are:\n", n);
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            printf("%d\n", i);
        }
    }

    return 0;
}

