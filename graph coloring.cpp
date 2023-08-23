#include <stdio.h>

#define MAX_VERTICES 20

int graph[MAX_VERTICES][MAX_VERTICES];
int numVertices, numColors;
int colors[MAX_VERTICES];


int isSafe(int vertex, int color) {
    for (int i = 0; i < numVertices; i++) {
        if (graph[vertex][i] && colors[i] == color) {
            return 0;
        }
    }
    return 1;
}


int graphColoring(int vertex) {
    if (vertex == numVertices) {
        return 1;
    }

    for (int color = 1; color <= numColors; color++) {
        if (isSafe(vertex, color)) {
            colors[vertex] = color;

            if (graphColoring(vertex + 1)) {
                return 1;
            }

            colors[vertex] = 0; 
        }
    }

    return 0;
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the number of colors: ");
    scanf("%d", &numColors);

    if (graphColoring(0)) {
        printf("Vertex coloring using %d colors:\n", numColors);
        for (int i = 0; i < numVertices; i++) {
            printf("Vertex %d: Color %d\n", i + 1, colors[i]);
        }
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}

