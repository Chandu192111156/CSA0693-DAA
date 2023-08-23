#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double value;
    double weight;
} Item;

int compare(const void *a, const void *b) {
    double ratioA = ((Item *)a)->value / ((Item *)a)->weight;
    double ratioB = ((Item *)b)->value / ((Item *)b)->weight;
    if (ratioA < ratioB)
        return 1;
    else if (ratioA > ratioB)
        return -1;
    else
        return 0;
}

double fractionalKnapsack(int n, Item items[], double capacity) {
    qsort(items, n, sizeof(Item), compare);
    
    double totalValue = 0.0;
    
    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            totalValue += (items[i].value / items[i].weight) * capacity;
            break;
        }
    }
    
    return totalValue;
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    Item items[n];
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%lf %lf", &items[i].value, &items[i].weight);
    }
    
    double capacity;
    printf("Enter the knapsack capacity: ");
    scanf("%lf", &capacity);
    
    double optimalValue = fractionalKnapsack(n, items, capacity);
    printf("Optimal value: %.2lf\n", optimalValue);
    
    return 0;
}

