#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool in_array(int* arr, int size_arr, int val) {
    for (int i = 0; i < size_arr; i++)
    {
        if (arr[i] == val)
        {
            return true;
        }
        
    }
    return false;
}

void array_add(int* arr, int* size_arr, int val) {
        *size_arr += 1;
        realloc(arr, *size_arr * sizeof(int));
        arr[*size_arr-1] = val;
}

bool dfs_is_safeNode(int currentNode, int** graph, int graphSize, int* graphColSize, int* branch, int branchSize, int* result, int* returnSize){
    if (graphColSize[currentNode] == 0)
    {
        if (!in_array(result, *returnSize, currentNode))
        {
            array_add(result, returnSize, currentNode);
        }
        
        return true;
    }

    if (in_array(result, *returnSize, currentNode))
    {
        return true;
    }
    

    // prevent circles
    if (in_array(branch, branchSize, currentNode))
    {
        return false;
    }

    array_add(branch, &branchSize, currentNode);
    


    bool is_safenode = true;
    int colpos = 0;

    while (is_safenode && colpos < graphColSize[currentNode])
    {
        is_safenode = dfs_is_safeNode(graph[currentNode][colpos], graph, graphSize, graphColSize, branch, branchSize, result, returnSize);
        colpos++;
    }
    
    if (is_safenode)
    {
        array_add(result, returnSize, currentNode);
    }
    return is_safenode;    
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* eventualSafeNodes(int** graph, int graphSize, int* graphColSize, int* returnSize){
    int* result = malloc(sizeof(int));
    int* branch;

    for (int i = 0; i < graphSize; i++)
    {
        branch = malloc(sizeof(int));
        dfs_is_safeNode(i, graph, graphSize, graphColSize, branch, 0, result, returnSize);
        free(branch);
    }
    
    qsort(result, *returnSize, sizeof(int), cmpfunc);
    return result;
}

void print_result(int* result, int resultSize) {
    printf("result: ");
    for (int i = 0; i < resultSize; i++)
    {
        printf("%d, ", result[i]);
    }
    printf("\n");
}

int main() {
    const int graphSize = 7;
    int graphColSize[] = {2,2,1,1,1, 0, 0};
    int* graph[graphSize];

    for (int i = 0; i < graphSize; i++)
    {
        graph[i] = malloc(graphColSize[i] * sizeof(int));
    }

    //[[1,2],[2,3],[5],[0],[5],[],[]]
    graph[0][0] = 1;
    graph[0][1] = 2;
    graph[1][0] = 2;
    graph[1][1] = 3;
    graph[2][0] = 5;
    graph[3][0] = 0;
    graph[4][0] = 5;

    // graph[0][0] = 1;
    // graph[0][1] = 2;
    // graph[0][2] = 3;
    // graph[0][3] = 4;
    // graph[1][0] = 1;
    // graph[1][1] = 2;
    // graph[2][0] = 3;
    // graph[2][1] = 4;
    // graph[3][0] = 0;
    // graph[3][1] = 4;

    int resultSize = 0;
    int* resultSize_p = &resultSize;
    int* result = eventualSafeNodes(graph, graphSize, graphColSize, resultSize_p);

    print_result(result, resultSize);

    return 0;
}