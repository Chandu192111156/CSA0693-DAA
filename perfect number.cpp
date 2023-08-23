#include <stdio.h>

int isPerfect(int num) {
    int sum = 0;
    
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    
    return sum == num;
}

int main() {
    int limit;
    printf("Enter a limit: ");
    scanf("%d", &limit);
    
    printf("Perfect numbers up to %d:\n", limit);
    
    for (int i = 1; i <= limit; i++) {
        if (isPerfect(i)) {
            printf("%d\n", i);
        }
    }
    
    return 0;
}

