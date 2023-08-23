#include <stdio.h>

#define MAX_VERTICES 10

int graph[MAX_VERTICES][MAX_VERTICES];
int numVertices;
int path[MAX_VERTICES];

int isSafe(int v, int pos, int path[]) {
    if (!graph[path[pos - 1]][v])
        return 0;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return 0;

    return 1;
}

int hamiltonianCycleUtil(int path[], int pos) {
    if (pos == numVertices) {
        if (graph[path[pos - 1]][path[0]]) 
            return 1;
        return 0;
    }

    for (int v = 1; v < numVertices; v++) {
        if (isSafe(v, pos, path)) {
            path[pos] = v;

            if (hamiltonianCycleUtil(path, pos + 1))
                return 1;

            path[pos] = -1;
        }
    }

    return 0;
}

int hamiltonianCycle(int startVertex) {
    path[0] = startVertex;

    if (!hamiltonianCycleUtil(path, 1)) {
        printf("No Hamiltonian cycle exists.\n");
        return 0;
    }

    printf("Hamiltonian cycle exists: ");
    for (int i = 0; i < numVertices; i++)
        printf("%d ", path[i]);
    printf("%d\n", path[0]);

    return 1;
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++)
        for (int j = 0; j < numVertices; j++)
            scanf("%d", &graph[i][j]);

    int startVertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    hamiltonianCycle(startVertex);

    return 0;
}

