//Count Nodes in Linked List

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 0) {
        printf("0");
        return 0;
    }

    struct ListNode *head = NULL, *temp = NULL, *newNode = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Count nodes
    int count = 0;
    temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("%d", count);

    return 0;
}