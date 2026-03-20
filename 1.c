#include <stdio.h>

int main() {
    int n, u, v;
    
    // Input number of nodes
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    
    int degree[n + 1];
    
    // Initialize degrees to 0
    for (int i = 1; i <= n; i++) {
        degree[i] = 0;
    }
    
    // Input edges
    printf("Enter %d edges (u v):\n", n - 1);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &u, &v);
        degree[u]++;
        degree[v]++;
    }
    
    int leaf_count = 0;
    
    // Count leaf nodes
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 1) {
            leaf_count++;
        }
    }
    
    // Special case: single node tree
    if (n == 1) {
        leaf_count = 1;
    }
    
    printf("Number of leaf nodes: %d\n", leaf_count);
    
    return 0;
}