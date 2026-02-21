#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void* a, const void* b) {
    int x = *(int*)a;
    int y = *(int*)b;
    if (x > y) return 1;
    if (x < y) return -1;
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    if(n < 2) {
        printf("Not enough elements\n");
        return 0;
    }

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;

    int minSum = arr[left] + arr[right];
    int num1 = arr[left], num2 = arr[right];

    while(left < right) {
        int sum = arr[left] + arr[right];

        if(abs(sum) < abs(minSum)) {
            minSum = sum;
            num1 = arr[left];
            num2 = arr[right];
        }

        if(sum < 0)
            left++;
        else
            right--;
    }

    printf("%d %d\n", num1, num2);

    return 0;
}
