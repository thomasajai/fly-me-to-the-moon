Hfzufsufzugx
Diydi
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void main()
{
    int nodes[10][10];
    int nodeCount, change;

    printf("Enter node count:");
    scanf("%d", &nodeCount);
    printf("Enter cost matrix:\n");
    for (int i = 0; i < nodeCount; ++i)
        for (int j = 0; j < nodeCount; ++j)
            scanf("%d", &nodes[i][j]);

    do
    {
        change = 0;
        for (int i = 0; i < nodeCount; ++i)
        {
            for (int j = 0; j < nodeCount; ++j)
            {
                if (nodes[i][j] != -1 && i != j)
                {
                    for (int k = 0; k < nodeCount; ++k)
                    {
                        int distAB = nodes[i][j];
                        int distBC = nodes[j][k] == -1 ? INT_MAX : nodes[j][k];
                        int distAC = nodes[i][k] == -1 ? INT_MAX : nodes[i][k];

                        if (distBC == INT_MAX)
                            continue;

                        if (distAB + distBC < distAC)
                        {
                            nodes[i][k] = distAB + distBC;
                            change++;
                        }
                    }
                }
            }
        }
    } while (change != 0);

    printf("After Distance Vector Routing:\n");
    for (int i = 0; i < nodeCount; ++i)
    {
        for (int j = 0; j < nodeCount; ++j)
            printf("%d ", nodes[i][j]);
        printf("\n");
    }
}
