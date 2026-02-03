#include <stdio.h>

int main() {
    int n, pos;

    // Read size of array
    scanf("%d", &n);

    int arr[n];

    // Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read position to delete (1-based)
    scanf("%d", &pos);

    // Check for valid position
    if (pos < 1 || pos > n) {
        // Invalid position: print original array
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        return 0;
    }

    // Shift elements to the left
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Print updated array (n-1 elements)
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
