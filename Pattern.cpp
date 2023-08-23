#include <stdio.h>

void print_pattern(int n) {
    for (int i = 1; i <= n; i++) {
        
        for (int space = 1; space <= n - i; space++) {
            printf(" ");
        }
        
        
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        
        printf("\n");  
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    print_pattern(n);
    return 0;
}

