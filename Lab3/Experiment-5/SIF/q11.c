#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define MAX_NAME 20

typedef struct {
    char name[MAX_NAME];
} Vertex;

Vertex vertices[MAX];
int adjMatrix[MAX][MAX];
int vertexCount = 0;

// Get index of vertex, add if not present
int getIndex(char *name) {
    for (int i = 0; i < vertexCount; i++) {
        if (strcmp(vertices[i].name, name) == 0)
            return i;
    }
    strcpy(vertices[vertexCount].name, name);
    return vertexCount++;
}

int main() {
    char v1[MAX_NAME], rel[MAX_NAME], v2[MAX_NAME];
    printf("Enter edges in SIF format: node1 relation node2 (type END to stop)\n");

    while (1) {
        scanf("%s", v1);
        if (strcmp(v1, "END") == 0) break;
        scanf("%s %s", rel, v2); // relation ignored, only graph needed

        int i = getIndex(v1);
        int j = getIndex(v2);
        adjMatrix[i][j] = 1; // directed edge
    }

    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < vertexCount; j++)
            printf("%d ", adjMatrix[i][j]);
        printf("\n");
    }

    return 0;
}
